#pragma once
#include <iostream>
//Клас точки в тривимірному просторі
class Point
{
private:
    static int _freeID;
    const int _pointID;
    static int _counter;
    double _x;
    double _y;
    double _z;

public:
    Point(double x = 0, double y = 0, double z = 0);
    Point(const Point&);

    ~Point();

    Point& operator= (const Point&);

    double& x() { return _x; };
    double& y() { return _y; };
    double& z() { return _z; };
    const double& x() const { return _x; };
    const double& y() const { return _y; };
    const double& z() const { return _z; };

    const int getID() const { return _pointID; };
    static int amount() { return _counter; };

    Point middle(const Point& v) const;

    //double angleCos(const Point& p1, const Point& p2) const {
    //    // Calculate vectors between points
    //    double vec1_x = p1._x - _x;
    //    double vec1_y = p1._y - _y;
    //    double vec1_z = p1._z - _z;

    //    double vec2_x = p2._x - _x;
    //    double vec2_y = p2._y - _y;
    //    double vec2_z = p2._z - _z;

    //    // Calculate dot product
    //    double dot_product = vec1_x * vec2_x + vec1_y * vec2_y + vec1_z * vec2_z;

    //    // Calculate lengths of vectors
    //    double length_vec1 = std::sqrt(vec1_x * vec1_x + vec1_y * vec1_y + vec1_z * vec1_z);
    //    double length_vec2 = std::sqrt(vec2_x * vec2_x + vec2_y * vec2_y + vec2_z * vec2_z);

    //    // Calculate cosine of angle
    //    double cosine = dot_product / (length_vec1 * length_vec2);

    //    return cosine;
    //}

    double pDistance(const Point& u, const Point& v);
    double distance(const Point& u);

};

std::ostream& operator<< (std::ostream&, const Point&);

const Point operator+ (const Point& u, const Point& v);

Point& operator+= (Point& u, const Point& v);

bool operator== (const Point& u, const Point& v);

bool operator!= (const Point& u, const Point& v);

