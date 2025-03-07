/**
* @file Homothetie.h
 * @brief Declaration of the Homothetie class for applying scaling transformations.
 *
 * This file defines the Homothetie class which derives from Transformation and applies a scaling
 * (homothety) to a geometric shape (Forme) using a specified center point and scaling factor.
 */

#ifndef HOMOTHETIE_H
#define HOMOTHETIE_H

#include "Transformation.h"
#include "Vecteur2D.h"

/**
 * @class Homothetie
 * @brief Applies a scaling transformation (homothety) to a geometric shape.
 *
 * The Homothetie class implements the Transformation interface to scale a shape. The transformation
 * is performed with respect to a specified center point and a scaling factor.
 */
class Homothetie : public Transformation {
    Vecteur2D center; /**< The center point for the scaling transformation. */
    double scale;     /**< The scaling factor used to resize the shape. */

public:
    /**
     * @brief Constructs a Homothetie transformation.
     * @param center The center point for the scaling.
     * @param scale The scaling factor.
     */
    Homothetie(const Vecteur2D& center, double scale)
        : center(center), scale(scale) {}

    /**
     * @brief Applies the scaling transformation to the provided shape.
     * @param forme The shape (Forme) to be scaled.
     *
     * This method applies the homothety transformation using the specified center and scaling factor.
     */
    void apply(Forme& forme) const override;
};

#endif // HOMOTHETIE_H
