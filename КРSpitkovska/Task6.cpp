#include "Task6.h"


bool Pyramide::validFaces(const Triangle& abc, const Triangle& asb, const Triangle& csa) const 
{
    return checkPyramid(abc.apexA(), abc.apexB(), abc.apexC(), _s) &&
        checkPyramid(asb.apexA(), asb.apexB(), asb.apexC(), _s) &&
        checkPyramid(csa.apexA(), csa.apexB(), csa.apexC(), _s);
}

void Pyramide::setVertexA(const Point& a)
{
    std::unique_ptr<Triangle> tempABC(new Triangle(a, _b, _c));
    std::unique_ptr<Triangle> tempASB(new Triangle(a, _s, _b));
    std::unique_ptr<Triangle> tempCSA(new Triangle(_c, _s, a));

    if (validFaces(*tempABC, *tempASB, *tempCSA)) {
        _a = a;
        _ABC = std::move(tempABC.release());
        _ASB = std::move(tempASB.release());
        _CSA = std::move(tempCSA.release());
    }
    else {
        throw std::invalid_argument("Invalid pyramid vertices after modification.");
    }
}

void Pyramide::setVertexB(const Point& b) {
    std::unique_ptr<Triangle> tempABC(new Triangle(_a, b, _c));
    std::unique_ptr<Triangle> tempASB(new Triangle(_a, _s, b));
    std::unique_ptr<Triangle> tempBSC(new Triangle(b, _s, _c));

    if (validFaces(*tempABC, *tempASB, *tempBSC)) {
        _b = b;
        _ABC = std::move(tempABC.release());
        _ASB = std::move(tempASB.release());
        _BSC = std::move(tempBSC.release());
    }
    else {
        throw std::invalid_argument("Invalid pyramid vertices after modification.");
    }
}

void Pyramide::setVertexC(const Point& c) {
    std::unique_ptr<Triangle> tempABC(new Triangle(_a, _b, c));
    std::unique_ptr<Triangle> tempBSC(new Triangle(_b, _s, c));
    std::unique_ptr<Triangle> tempCSA(new Triangle(c, _s, _a));

    if (validFaces(*tempABC, *tempBSC, *tempCSA)) {
        _c = c;
        _ABC = std::move(tempABC.release());
        _BSC = std::move(tempBSC.release());
        _CSA = std::move(tempCSA.release());
    }
    else {
        throw std::invalid_argument("Invalid pyramid vertices after modification.");
    }
}

void Pyramide::setVertexS(const Point& s) {
    std::unique_ptr<Triangle> tempASB(new Triangle(_a, s, _b));
    std::unique_ptr<Triangle> tempBSC(new Triangle(_b, s, _c));
    std::unique_ptr<Triangle> tempCSA(new Triangle(_c, s, _a));

    if (validFaces(*tempASB, *tempBSC, *tempCSA)) {
        _s = s;
        _ASB = std::move(tempASB.release());
        _BSC = std::move(tempBSC.release());
        _CSA = std::move(tempCSA.release());
    }
    else {
        throw std::invalid_argument("Invalid pyramid vertices after modification.");
    }
}



bool Pyramide::checkPyramid(const Point& a, const Point& b, const Point& c, const Point& s)
{
    //  чи всі точки різні
    if ((a == b) || (a == c) || (a == s) || (b == c) || (b == s) || (c == s)) 
    {
        return false;
    }
    return true;
}

Pyramide& Pyramide::operator=(const Pyramide& other)
{
    if (this != &other)
    {
        _a = other._a;
        _b = other._b;
        _c = other._c;
        _s = other._s;
        
        _ABC = new Triangle(*other._ABC);
        _ASB = new Triangle(*other._ASB);
        _BSC = new Triangle(*other._BSC);
        _CSA = new Triangle(*other._CSA);
    }
    return *this;
}

double Pyramide::volume() {
    // Calculate the base area using one of the triangle faces (let's use _ABC)
    double baseArea = _ABC->area();

    // Calculate the centroid of the base triangle
    Point baseCentroid = _ABC->centroid();

    // Calculate the height of the pyramid using the distance between the apex and the centroid of the base triangle
    double height = _s.distance(baseCentroid);

    // Calculate and return the volume using the formula V = (1/3) * baseArea * height
    return (1.0 / 3) * baseArea * height;
}

std::ostream& operator<<(std::ostream& os, const Pyramide& pyr) {
    os << "Pyramide  vertices:" << std::endl;
    os << "A: " << pyr.apexA() << std::endl;
    os << "B: " << pyr.apexB() << std::endl;
    os << "C: " << pyr.apexC() << std::endl;
    os << "S: " << pyr.apexS() << std::endl;
    return os;
}
