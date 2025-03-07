/**
* @file Rotation.h
 * @brief Declaration of the Rotation class for applying rotation transformations.
 *
 * This file defines the Rotation class which derives from Transformation and applies a rotation
 * to a geometric shape (Forme) around a specified center point by a given angle.
 */

#ifndef ROTATION_H
#define ROTATION_H

#include "Transformation.h"
#include "Vecteur2D.h"

/**
 * @class Rotation
 * @brief Applies a rotation transformation to a geometric shape.
 *
 * The Rotation class implements the Transformation interface to rotate a shape around a
 * specified center point by a given angle (in radians).
 */
class Rotation : public Transformation {
    Vecteur2D center; /**< The center point around which the shape will be rotated. */
    double angle;     /**< The rotation angle in radians. */

public:
    /**
     * @brief Constructs a Rotation transformation.
     * @param center The center point for the rotation.
     * @param angle The angle of rotation in radians.
     */
    Rotation(const Vecteur2D& center, double angle)
        : center(center), angle(angle) {}

    /**
     * @brief Applies the rotation to the provided shape.
     * @param forme The shape (Forme) to be rotated.
     *
     * This method applies the stored rotation transformation (using the center and angle) to the given shape.
     */
    void apply(Forme& forme) const override;
};

#endif // ROTATION_H
