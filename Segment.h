/**
 * @file Segment.h
 * @brief Declaration of the Segment class representing a line segment.
 *
 * This file defines the Segment class which is derived from Forme and models a line segment
 * defined by two endpoints. It supports geometric transformations and provides methods for
 * calculating its area, converting its properties to a string, and performing drawing and
 * saving operations via the Visitor design pattern.
 */

#ifndef SEGMENT_H
#define SEGMENT_H

#include "Forme.h"
#include "Vecteur2D.h"

/**
 * @class Segment
 * @brief Represents a line segment defined by two endpoints.
 *
 * The Segment class models a line segment using two Vecteur2D objects as its endpoints.
 * It implements methods to apply geometric transformations (translation, homothety, and rotation),
 * and includes functionality for calculating the segment's area (typically 0 for a line segment)
 * and converting its properties to a string representation. The Visitor design pattern is used
 * for drawing and saving operations.
 */
class Segment : public Forme {
    Vecteur2D p1, p2; /**< The endpoints of the segment. */

public:
    /**
     * @brief Constructs a Segment object with two endpoints and an optional color.
     * @param p1 The first endpoint of the segment.
     * @param p2 The second endpoint of the segment.
     * @param color The color of the segment. Default is "black".
     */
    Segment(const Vecteur2D& p1, const Vecteur2D& p2, const string& color = "black");

    /**
     * @brief Retrieves the first endpoint of the segment.
     * @return A Vecteur2D representing the first endpoint.
     */
    Vecteur2D getP1() const;

    /**
     * @brief Retrieves the second endpoint of the segment.
     * @return A Vecteur2D representing the second endpoint.
     */
    Vecteur2D getP2() const;

    /**
     * @brief Translates the segment by a given vector.
     * @param translationVector The vector by which to translate the segment.
     */
    void translate(const Vecteur2D& translationVector) override;

    /**
     * @brief Applies a homothety (scaling transformation) to the segment.
     * @param center The center of the homothety.
     * @param scale The scaling factor.
     */
    void homothetie(const Vecteur2D& center, double scale) override;

    /**
     * @brief Rotates the segment around a specified center.
     * @param center The center of rotation.
     * @param angle The rotation angle in radians.
     */
    void rotate(const Vecteur2D& center, double angle) override;

    /**
     * @brief Calculates the area of the segment.
     * @return The area of the segment as a double.
     *
     * Note: For a line segment, the area is conventionally considered to be 0.
     */
    double calculateArea() const override;

    /**
     * @brief Converts the segment to a string representation.
     * @return A string describing the segment, including its endpoints and color.
     */
    string toString() const override;

    /**
     * @brief Draws the segment using a visitor.
     * @param v Pointer to a Visiteur object that handles the drawing operation.
     *
     * This method utilizes the Visitor design pattern to perform the drawing operation.
     */
    void draw(const Visiteur *v) const override {
        v->visit(*this);
    }

    /**
     * @brief Saves the segment using a visitor.
     * @param v Pointer to a Visiteur object that handles the saving operation.
     *
     * This method utilizes the Visitor design pattern to perform the saving operation.
     */
    void save(const Visiteur *v) const override {
        v->visit(*this);
    }
};

#endif // SEGMENT_H
