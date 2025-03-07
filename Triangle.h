/**
 * @file Triangle.h
 * @brief Declaration of the Triangle class representing a triangle shape.
 *
 * This file defines the Triangle class which derives from Forme and models a triangle defined
 * by three vertices. The class supports geometric transformations such as translation, homothety,
 * and rotation, and implements methods for area calculation, string conversion, drawing, and saving
 * using the Visitor design pattern.
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Forme.h"
#include "Vecteur2D.h"

/**
 * @class Triangle
 * @brief Represents a triangle shape.
 *
 * The Triangle class represents a triangle defined by three vertices (p1, p2, and p3).
 * It provides methods for geometric transformations and computes its area. It also supports
 * drawing and saving operations via the Visitor design pattern.
 */
class Triangle : public Forme {
    Vecteur2D p1, p2, p3; /**< Vertices of the triangle. */

public:
    /**
     * @brief Constructs a Triangle object with the given vertices and color.
     * @param p1 The first vertex.
     * @param p2 The second vertex.
     * @param p3 The third vertex.
     * @param color The color of the triangle. Default is "black".
     */
    Triangle(const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3, const string& color = "black");

    /**
     * @brief Copy constructor for the Triangle class.
     * @param tri The Triangle object to copy.
     */
    Triangle(const Triangle& tri);

    /**
     * @brief Retrieves the first vertex of the triangle.
     * @return A Vecteur2D representing the first vertex.
     */
    Vecteur2D getP1() const;

    /**
     * @brief Retrieves the second vertex of the triangle.
     * @return A Vecteur2D representing the second vertex.
     */
    Vecteur2D getP2() const;

    /**
     * @brief Retrieves the third vertex of the triangle.
     * @return A Vecteur2D representing the third vertex.
     */
    Vecteur2D getP3() const;

    /**
     * @brief Translates the triangle by a given vector.
     * @param translationVector The vector by which the triangle is translated.
     */
    void translate(const Vecteur2D& translationVector) override;

    /**
     * @brief Applies a homothety (scaling transformation) to the triangle.
     * @param center The center point for the homothety.
     * @param scale The scaling factor.
     */
    void homothetie(const Vecteur2D& center, double scale) override;

    /**
     * @brief Rotates the triangle around a specified center.
     * @param center The center of rotation.
     * @param angle The rotation angle in radians.
     */
    void rotate(const Vecteur2D& center, double angle) override;

    /**
     * @brief Calculates the area of the triangle.
     * @return The area of the triangle as a double.
     */
    double calculateArea() const override;

    /**
     * @brief Returns a string representation of the triangle.
     * @return A string describing the triangle, including its vertices and color.
     */
    string toString() const override;

    /**
     * @brief Draws the triangle using a visitor.
     * @param v Pointer to a Visiteur object that handles the drawing operation.
     *
     * This method applies the Visitor design pattern to perform the drawing.
     */
    void draw(const Visiteur *v) const override {
        v->visit(*this);
    }

    /**
     * @brief Saves the triangle using a visitor.
     * @param v Pointer to a Visiteur object that handles the saving operation.
     *
     * This method applies the Visitor design pattern to perform the saving.
     */
    void save(const Visiteur *v) const override {
        v->visit(*this);
    }
};

#endif // TRIANGLE_H
