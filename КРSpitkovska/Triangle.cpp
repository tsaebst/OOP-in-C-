//written by Spitkovska
#include "Point.h"
#include "Segment.h"
#include "Triangle.h"
#include <math.h>
#include <io.h>
#include <assert.h>




Triangle::Triangle(const double x1, const double y1, const double x2,
    const double y2, const double x3, const double y3) :
    _a(x1, y1), _b(x2, y2), _c(x3, y3),
    _cMiddle(_a.middle(_b)),
    _aMiddle(_b.middle(_c)),
    _bMiddle(_c.middle(_a)) {}

// Конструктор трикутника за його вершинами 
Triangle::Triangle(const Point& a, const Point& b, const Point& c) :
    _a(a), _b(b), _c(c),
    _cMiddle(_a.middle(_b)),
    _aMiddle(_b.middle(_c)),
    _bMiddle(_c.middle(_a)) {}


// Constructor taking a segment and a point
Triangle::Triangle(const Segment& seg, const Point& c) :
    _a(seg.start()), _b(seg.end()), _c(c),
    _cMiddle(_a.middle(_b)),
    _aMiddle(_b.middle(_c)),
    _bMiddle(_c.middle(_a)) {}

// Constructor taking a segment and coordinates
Triangle::Triangle(const Segment& seg, double x, double y) :
    _a(seg.start()), _b(seg.end()), _c(Point(x, y)),
    _cMiddle(_a.middle(_b)),
    _aMiddle(_b.middle(_c)),
    _bMiddle(_c.middle(_a)) {}

// Копіювальний конструктор
Triangle::Triangle(const Triangle& t) :
    // Ініціалізація вершин за допомогою копіювальних конструкторів
    _a(t._a), _b(t._b), _c(t._c) {}

// Деструктор
Triangle::~Triangle() {}

// Присвоєння
Triangle& Triangle::operator=(const Triangle& t) {
    _a = t._a; _b = t._b; _c = t._c;
    return *this;
}

//modificators
void Triangle::operator()(const double x1, const double y1, const double x2,
    const double y2, const double x3, const double y3)
{
    _a = Point(x1, y1);
    _b = Point(x2, y2);
    _c = Point(x3, y3);
    _cMiddle = _a.middle(_b);
    _aMiddle = _b.middle(_c);
    _bMiddle = _c.middle(_a);
}

void Triangle::operator()(const Point& a, const Point& b, const Point& c)
{
    _a = a;
    _b = b;
    _c = c;
    _cMiddle = _a.middle(_b);
    _aMiddle = _b.middle(_c);
    _bMiddle = _c.middle(_a);
}


void Triangle::operator()(const Segment& seg, const Point& v)
{
    _a = seg.start();
    _b = seg.end();
    _c = v;
    _cMiddle = _a.middle(_b);
    _aMiddle = _b.middle(_c);
    _bMiddle = _c.middle(_a);
}

void Triangle::operator()(const Segment& seg, double x, double y)
{
    _a = seg.start();
    _b = seg.end();
    _c = Point(x, y);
    _cMiddle = _a.middle(_b);
    _aMiddle = _b.middle(_c);
    _bMiddle = _c.middle(_a);
}


double Triangle::perimeter() const {
    return side_a().length() + side_b().length() + side_c().length();
}

double Triangle::area() const
{
    double sp = (side_a().length() + side_b().length() + side_c().length()) / 2;
    double s = sqrt(sp * (sp - side_a().length()) * (sp - side_b().length()) * (sp - side_c().length()));
    return s;
}

const Segment& Triangle::medianA() const {
#ifdef NDEBUG
    std::cout << "MIDDLE: " << _aMiddle << std::endl;
#endif
    Segment temp(_aMiddle, _a);
    _median_a = new Segment(temp);
    return *_median_a;
}

const Segment& Triangle::medianB() const {
#ifdef NDEBUG
    std::cout << "MIDDLE: " << _bMiddle << std::endl;
#endif
    Segment temp(_bMiddle, _b);
    _median_b = new Segment(temp);
    return *_median_b;
}

const Segment& Triangle::medianC() const
{
#ifdef NDEBUG
    std::cout << "MIDDLE: " << _cMiddle << std::endl;
#endif
    Segment temp(_cMiddle, _c);
    _median_c = new Segment(temp);
    return *_median_c;
}

std::ostream& operator<<(std::ostream& os, const Triangle& t)
{
    return os << "Triangle: {" << t.apexA() << ' ' << t.apexB() << ' ' << t.apexC() << "}";
}

//side re-setter 
const Segment& Triangle::side_a(const Point& start, const Point& end)
{
    if (start != end && start != _a && _a != end)
    {
        if (_bc) delete _bc;
        _bc = new Segment(start, end);
        _b = start;
        _c = end;
    }
    return *_bc;
}

const Segment& Triangle::side_b(const Point& start, const Point& end)
{
    if (start != end && start != _b && _b != end)
    {
        if (_ca) delete _ca;
        _ca = new Segment(start, end);
        _c = start;
        _a = end;
        return *_ca;
    }
}

const Segment& Triangle::side_c(const Point& start, const Point& end)
{
    if (start != end && start != _c && _c != end)
    {
        if (_ab) delete _ab;
        _ab = new Segment(start, end);
        _a = start;
        _b = end;
        return *_ab;
    }
}


const Segment& Triangle::side_a(const Segment& seg)
{
    if (seg.start() != seg.end() && seg.start() != _a && _a != seg.end())
    {
        if (_bc) delete _bc;
        _bc = new Segment(seg.start(), seg.end());
        _b = seg.start();
        _c = seg.end();
        return *_bc;
    }
}

const Segment& Triangle::side_b(const Segment& seg)
{
    if (seg.start() != seg.end() && seg.start() != _b && _b != seg.end())
    {
        if (_ca) delete _ca;
        _ca = new Segment(seg.start(), seg.end());
        _c = seg.start();
        _a = seg.end();
        return *_ca;
    }
}

const Segment& Triangle::side_c(const Segment& seg)
{
    if (seg.start() != seg.end() && seg.start() != _c && seg.end() != _c)
    {
        if (_ab) delete _ab;
        _ab = new Segment(seg.start(), seg.end());
        _a = seg.start();
        _b = seg.end();
        return *_ab;
    }
}

const Segment& Triangle::side_a(double x1, double y1, double x2, double y2)
{
    Point b(x1, y1);
    Point c(x2, y2);
    if (b != c && c != _a && b != _a)
    {
        delete _bc;
        _bc = new Segment(b, c);
        _b = b;
        _c = c;
        return *_bc;
    }
}
const Segment& Triangle::side_b(double x1, double y1, double x2, double y2)
{

    Point c(x1, y1);
    Point a(x2, y2);
    if (a != c && a != _b && c != _b)
    {
        delete _ca;
        _ca = new Segment(c, a);
        _a = a;
        _b = c;
    }
    return *_ca;
}

const Segment& Triangle::side_c(double x1, double y1, double x2, double y2)
{

    Point a(x1, y1);
    Point b(x2, y2);
    if (b != a && b != _c && a != _c)
    {
        delete _ab;
        _ca = new Segment(a, b);
        _a = a;
        _b = b;
    }
    return *_ab;
}