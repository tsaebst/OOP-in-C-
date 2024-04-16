#pragma once
#include "Triangle.h"
#include"Point.h"
#include <iostream>

class Pyramide
{
private:
    Point _a, _b, _c, _s;
    //mutable Segment* _ab, * _bc, * _ac, * _as, * _bs, * _cs;
    Triangle *_ABC, *_ASB, *_BSC, *_CSA; // Чотири грані піраміди

public:


    Pyramide(const Point& a, const Point& b, const Point& c, const Point& s)
        : _a(a), _b(b), _c(c), _s(s), _ABC(nullptr), _ASB(nullptr), _BSC(nullptr), _CSA(nullptr)
    {   

        if (!checkPyramid(a, b, c, s)) {
            throw std::invalid_argument("Invalid pyramid vertices. Please ensure that all vertices are distinct and form a valid pyramid.");
        }
        //Створення граней
        _ABC = new Triangle(_a, _b, _c);
        _ASB = new Triangle(_a, _s, _b);
        _BSC = new Triangle(_b, _s, _c);
        _CSA = new Triangle(_c, _s, _a);
    };

    ~Pyramide()
    {
        //delete _ABC;
        //delete _ASB;
        //delete _BSC;
        //delete _CSA;
    }

    Pyramide& operator=(const Pyramide&);


    const Point& apexA() const { return _a; }
    const Point& apexB() const { return _b; }
    const Point& apexC() const { return _c; }
    const Point& apexS() const { return _s; }

    Point& apexA() { return _a; }
    Point& apexB() { return _b; }
    Point& apexC() { return _c; }
    Point& apexS() { return _s; }

    // Копіювальний конструктор
    Pyramide(const Pyramide& other)
        : _a(other._a), _b(other._b), _c(other._c), _s(other._s),
        _ABC(other._ABC), _ASB(other._ASB), _BSC(other._BSC), _CSA(other._CSA) {}

    // Селектори для граней
    const Triangle& faceABC() const { return *_ABC; }
    const Triangle& faceBSC() const { return *_BSC; }
    const Triangle& faceASB() const { return *_ASB; }
    const Triangle& faceCSA() const { return *_CSA; }

    // Модифікатор для вершини A
    void setVertexA(const Point& a);

    // Модифікатор для вершини B
    void setVertexB(const Point& b);

    // Модифікатор для вершини C
    void setVertexC(const Point& c);

    // Модифікатор для вершини S
    void setVertexS(const Point& s);

    // Функція для перевірки умов для побудови піраміди
    static bool checkPyramid(const Point& a, const Point& b, const Point& c, const Point& s);

    bool validFaces(const Triangle& abc, const Triangle& asb, const Triangle& csa) const;

    double volume();

    friend std::ostream& operator<<(std::ostream& os, const Pyramide& triangle);
};

