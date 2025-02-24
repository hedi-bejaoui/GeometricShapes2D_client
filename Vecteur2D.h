//
// Created by bejaoui on 12/25/2024.
//

#ifndef VECTEUR2D_H
#define VECTEUR2D_H

#include <math.h>
#include <ostream>
#include <string>
#include <sstream>
#include <valarray>

using namespace std;

/**
 * class Vecteur2D, a vector is an (x, y) allowing to represent
 * a point on the plane, a vector, or a complex number.
 */
class Vecteur2D {
public:

    double x, y; // abscissa and ordinate
    string color; // color of the vector

    explicit Vecteur2D(const double & x = 0, const double & y = 0, const string & color = "black") : x(x), y(y), color(validateColor(color)) {}

    // Validate the color to ensure it is within the allowed set
    static string validateColor(const string & color) {
        const string allowedColors[] = {"black", "blue", "red", "green", "yellow", "cyan"};
        for (const string & allowed : allowedColors) {
            if (color == allowed) {
                return color;
            }
        }
        throw invalid_argument("Invalid color. Allowed colors are: black, blue, red, green, yellow, cyan.");
    }

    //---------------Algebraic Operations---------------//
    const Vecteur2D & operator += (const Vecteur2D & v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    const Vecteur2D operator + (const Vecteur2D & v) const {
        Vecteur2D r(*this);
        return r += v;
    }

    const Vecteur2D operator - () const {
        return Vecteur2D(-x, -y, color);
    }

    const Vecteur2D operator - (const Vecteur2D & v) const {
        return *this + -v;
    }

    const Vecteur2D operator * (const double & a) const {
        return Vecteur2D(x * a, y * a, color);
    }

    /* Dot product */
    const double operator * (const Vecteur2D & v) const {
        return x * v.x + y * v.y;
    }

    double const normeCarree() const {
        return *this * *this;
    }

    double const norme() const {
        return sqrt(normeCarree());
    }

    double det(const Vecteur2D & v) const {
        return x * v.y - y * v.x;
    }

    operator string() const {
        ostringstream o;
        o << "(" << x << ", " << y << ", color: " << color << ")" ;
        return o.str();
    }
};

inline ostream & operator << (ostream & o, const Vecteur2D & v) {
    return o << string(v);
}

inline const Vecteur2D operator * (const double & a, const Vecteur2D & v) {
    return v * a;
}

#endif // VECTEUR2D_H

