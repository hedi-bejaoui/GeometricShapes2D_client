/**
* @file Translation.h
 * @brief Declaration of the Translation class for applying translation transformations.
 *
 * This file defines the Translation class which derives from Transformation and applies a translation
 * (shift) to a geometric shape (Forme) using a given translation vector.
 */

#ifndef TRANSLATION_H
#define TRANSLATION_H

#include "Transformation.h"
#include "Vecteur2D.h"

/**
 * @class Translation
 * @brief Applies a translation vector to a geometric shape.
 *
 * The Translation class implements the Transformation interface to apply a translation to a shape.
 * The transformation shifts the shape's position by the specified translation vector.
 */
class Translation : public Transformation {
    Vecteur2D translationVector; /**< The translation vector used to shift the shape. */

public:
    /**
     * @brief Constructs a Translation transformation.
     * @param translationVector The vector by which to translate a shape.
     */
    explicit Translation(const Vecteur2D& translationVector)
        : translationVector(translationVector) {}

    /**
     * @brief Applies the translation to the provided shape.
     * @param forme The shape (Forme) to be translated.
     *
     * This method applies the stored translation vector to the given shape.
     */
    void apply(Forme& forme) const override;
};

#endif // TRANSLATION_H
