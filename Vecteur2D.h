/**
 * @file Vecteur2D.h
 * @brief Header file for the Vecteur2D class.
 *
 * This file defines the Vecteur2D class which represents a 2D vector (or point)
 * along with an associated color. A Vecteur2D can be used to represent a point on
 * the plane, a vector, or even a complex number.
 */

#ifndef VECTEUR2D_H
#define VECTEUR2D_H

#include <math.h>
#include <ostream>
#include <string>
#include <sstream>
#include <valarray>

using namespace std;

/**
 * @class Vecteur2D
 * @brief Represents a 2D vector, point, or complex number with a color attribute.
 *
 * The Vecteur2D class encapsulates x and y components of a 2D vector and includes a color.
 * The color is validated against a predefined set of allowed colors: "black", "blue",
 * "red", "green", "yellow", and "cyan".
 */
class Vecteur2D {
public:

    double x, y; /**< The x (abscissa) and y (ordinate) components of the vector. */
    string color; /**< The color of the vector. Allowed colors: black, blue, red, green, yellow, cyan. */

    /**
     * @brief Constructs a Vecteur2D object.
     * @param x The x component (default is 0).
     * @param y The y component (default is 0).
     * @param color The color of the vector (default is "black").
     *
     * The color is validated using the validateColor static method.
     */
    explicit Vecteur2D(const double & x = 0, const double & y = 0, const string & color = "black") : x(x), y(y), color(validateColor(color)) {}

    /**
     * @brief Validates that the provided color is allowed.
     * @param color The color to validate.
     * @return The validated color if it is allowed.
     * @throw invalid_argument if the color is not one of the allowed values.
     *
     * Allowed colors are: "black", "blue", "red", "green", "yellow", "cyan".
     */
    static string validateColor(const string & color) {
        const string allowedColors[] = {"black", "blue", "red", "green", "yellow", "cyan"};
        for (const string & allowed : allowedColors) {
            if (color == allowed) {
                return color;
            }
        }
        throw invalid_argument("Invalid color. Allowed colors are: black, blue, red, green, yellow, cyan.");
    }

    //--------------- Algebraic Operations ---------------//

    /**
     * @brief Adds another vector to this vector.
     * @param v The vector to add.
     * @return A reference to this vector after addition.
     */
    const Vecteur2D & operator += (const Vecteur2D & v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    /**
     * @brief Returns the sum of this vector and another vector.
     * @param v The vector to add.
     * @return A new Vecteur2D representing the sum.
     */
    const Vecteur2D operator + (const Vecteur2D & v) const {
        Vecteur2D r(*this);
        return r += v;
    }

    /**
     * @brief Returns the negation of this vector.
     * @return A new Vecteur2D representing the negation.
     */
    const Vecteur2D operator - () const {
        return Vecteur2D(-x, -y, color);
    }

    /**
     * @brief Subtracts another vector from this vector.
     * @param v The vector to subtract.
     * @return A new Vecteur2D representing the difference.
     */
    const Vecteur2D operator - (const Vecteur2D & v) const {
        return *this + -v;
    }

    /**
     * @brief Multiplies the vector by a scalar.
     * @param a The scalar value.
     * @return A new Vecteur2D scaled by the given scalar.
     */
    const Vecteur2D operator * (const double & a) const {
        return Vecteur2D(x * a, y * a, color);
    }

    /**
     * @brief Computes the dot product with another vector.
     * @param v The other vector.
     * @return The dot product as a double.
     */
    const double operator * (const Vecteur2D & v) const {
        return x * v.x + y * v.y;
    }

    /**
     * @brief Computes the squared norm (magnitude) of the vector.
     * @return The squared norm as a double.
     */
    double const normeCarree() const {
        return *this * *this;
    }

    /**
     * @brief Computes the norm (magnitude) of the vector.
     * @return The norm as a double.
     */
    double const norme() const {
        return sqrt(normeCarree());
    }

    /**
     * @brief Computes the determinant (cross product in 2D) with another vector.
     * @param v The other vector.
     * @return The determinant value.
     */
    double det(const Vecteur2D & v) const {
        return x * v.y - y * v.x;
    }

    /**
     * @brief Converts the vector to a string representation.
     * @return A string in the format "(x, y, color: color)".
     */
    operator string() const {
        ostringstream o;
        o << "(" << x << ", " << y << ", color: " << color << ")" ;
        return o.str();
    }
};

/**
 * @brief Overloads the output stream operator for Vecteur2D.
 * @param o The output stream.
 * @param v The Vecteur2D object to output.
 * @return A reference to the output stream.
 */
inline ostream & operator << (ostream & o, const Vecteur2D & v) {
    return o << string(v);
}

/**
 * @brief Multiplies a scalar with a Vecteur2D (commutative operation).
 * @param a The scalar multiplier.
 * @param v The Vecteur2D object.
 * @return A new Vecteur2D representing the product.
 */
inline const Vecteur2D operator * (const double & a, const Vecteur2D & v) {
    return v * a;
}

#endif // VECTEUR2D_H
