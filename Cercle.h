/**
 * @file Cercle.h
 * @brief Declaration of the Cercle class representing a circle shape.
 *
 * The Cercle class derives from Forme and models a circle with a center and a radius.
 * It implements geometric transformations (translation, homothety, rotation), and provides
 * methods to save and draw itself via a visitor.
 */

#ifndef CERCLE_H
#define CERCLE_H

#include "Forme.h"
#include "Vecteur2D.h"

/**
 * @class Cercle
 * @brief Represents a circle shape.
 *
 * This class implements the abstract Forme interface for a circle. A circle is defined by its center
 * (a Vecteur2D) and its radius (a double). It supports basic geometric transformations and utilizes
 * the Visitor design pattern for drawing and saving.
 */
class Cercle : public Forme {
public:
    Vecteur2D center; /**< Center of the circle. */
    double radius;    /**< Radius of the circle. */

    /**
     * @brief Constructs a Cercle object.
     * @param center The center of the circle.
     * @param radius The radius of the circle.
     * @param color The color of the circle. Default is "black".
     */
    Cercle(const Vecteur2D& center, double radius, const string& color = "black");

    /**
     * @brief Translates the circle by a given vector.
     * @param translationVector The vector by which the circle is translated.
     */
    void translate(const Vecteur2D& translationVector) override;

    /**
     * @brief Applies a homothety (scaling transformation) to the circle.
     * @param centerPoint The center of the homothety.
     * @param scale The scaling factor.
     */
    void homothetie(const Vecteur2D& centerPoint, double scale) override;

    /**
     * @brief Rotates the circle around a given center.
     * @param centerPoint The center of rotation.
     * @param angle The rotation angle in radians.
     */
    void rotate(const Vecteur2D& centerPoint, double angle) override;

    /**
     * @brief Saves the circle using a visitor.
     * @param v Pointer to a Visiteur object that handles the save operation.
     *
     * This method utilizes the Visitor design pattern to save the circle's data.
     */
    void save(const Visiteur *v) const override {
        v->visit(*this);
    }

    /**
     * @brief Draws the circle using a visitor.
     * @param v Pointer to a Visiteur object that handles the drawing operation.
     *
     * This method utilizes the Visitor design pattern to draw the circle.
     */
    void draw(const Visiteur *v) const override {
        v->visit(*this);
    }

    /**
     * @brief Calculates the area of the circle.
     * @return The area as a double.
     */
    double calculateArea() const override;

    /**
     * @brief Returns a string representation of the circle.
     * @return A string describing the circle, including its center, radius, and color.
     */
    string toString() const override;
};

#include "Visteur.h"

#endif // CERCLE_H
