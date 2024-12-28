//
// Created by bejaoui on 12/28/2024.
//

#ifndef TRANSLATION_H
#define TRANSLATION_H

#include "Transformation.h"
#include "Vecteur2D.h"

/** Translation class applies a translation vector to a shape */
class Translation : public Transformation {
    Vecteur2D translationVector;

public:
    explicit Translation(const Vecteur2D& translationVector)
        : translationVector(translationVector) {}

    void apply(Forme& forme) const override;
};

#endif // TRANSLATION_H
