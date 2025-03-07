/**
 * @file Polygone.h
 * @brief Declaration of the Polygone class representing a polygon shape.
 *
 * This file defines the Polygone class, which derives from Forme and represents a closed polygon
 * defined by a series of 2D points. It implements geometric transformations and supports drawing
 * and saving operations using the Visitor design pattern.
 */

#ifndef POLYGONE_H
#define POLYGONE_H

#include "Forme.h"
#include "Vecteur2D.h"
#include <vector>

/**
 * @class Polygone
 * @brief Represents a polygon shape.
 *
 * The Polygone class models a closed polygon defined by a vector of Vecteur2D points.
 * It supports standard geometric transformations such as translation, homothety, and rotation.
 * Additionally, it implements methods for drawing and saving via the Visitor design pattern.
 */
class Polygone : public Forme {

    std::vector<Vecteur2D> points; /**< Points that define the polygon. */

public:

    /**
     * @brief Constructs a Polygone object.
     * @param points A vector of Vecteur2D points defining the polygon.
     * @param color The color of the polygon. Default is "black".
     */
    Polygone(const std::vector<Vecteur2D>& points, const std::string& color = "black");

    /**
     * @brief Retrieves the points that define the polygon.
     * @return A constant reference to the vector of Vecteur2D points.
     */
    const std::vector<Vecteur2D>& getPoints() const {
        return points;
    }

    /**
     * @brief Translates the polygon by a given vector.
     * @param translationVector The vector by which to translate the polygon.
     */
    void translate(const Vecteur2D& translationVector) override;

    /**
     * @brief Applies a homothety (scaling transformation) to the polygon.
     * @param center The center point for the homothety.
     * @param scale The scaling factor.
     */
    void homothetie(const Vecteur2D& center, double scale) override;

    /**
     * @brief Rotates the polygon around a specified center.
     * @param center The center of rotation.
     * @param angle The rotation angle in radians.
     */
    void rotate(const Vecteur2D& center, double angle) override;

    /**
     * @brief Draws the polygon using a visitor.
     * @param v Pointer to a Visiteur object that handles drawing.
     *
     * This method uses the Visitor design pattern to draw the polygon.
     */
    void draw(const Visiteur *v) const override {
        v->visit(*this);
    }

    /**
     * @brief Saves the polygon using a visitor.
     * @param v Pointer to a Visiteur object that handles saving.
     *
     * This method uses the Visitor design pattern to save the polygon.
     */
    void save(const Visiteur *v) const override {
        v->visit(*this);
    }

    /**
     * @brief Calculates the area of the polygon.
     * @return The area of the polygon as a double.
     */
    double calculateArea() const override;

    /**
     * @brief Converts the polygon to a string representation.
     * @return A string describing the polygon.
     */
    std::string toString() const override;
};

#endif // POLYGONE_H
