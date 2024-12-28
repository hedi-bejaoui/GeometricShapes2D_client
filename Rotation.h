//
// Created by bejaoui on 12/28/2024.
//

#ifndef ROTATION_H
#define ROTATION_H

#include "Transformation.h"
#include "Vecteur2D.h"

/** Rotation class applies rotation to a shape */
class Rotation : public Transformation {
    Vecteur2D center;
    double angle;

public:
    Rotation(const Vecteur2D& center, double angle)
        : center(center), angle(angle) {}

    void apply(Forme& forme) const override;
};

#endif // ROTATION_H
