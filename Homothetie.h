//
// Created by bejaoui on 12/28/2024.
//

#ifndef HOMOTHETIE_H
#define HOMOTHETIE_H

#include "Transformation.h"
#include "Vecteur2D.h"

/** Homothetie class applies scaling to a shape */
class Homothetie : public Transformation {
    Vecteur2D center;
    double scale;

public:
    Homothetie(const Vecteur2D& center, double scale)
        : center(center), scale(scale) {}

    void apply(Forme& forme) const override;
};

#endif // HOMOTHETIE_H
