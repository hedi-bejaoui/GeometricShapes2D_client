//
// Created by bejaoui on 12/25/2024.
//

#ifndef POLYGONE_H
#define POLYGONE_H

#include "Forme.h"
#include "Vecteur2D.h"
#include <vector>

/** Polygone class */
class Polygone : public Forme {
    vector<Vecteur2D> points;

public:
    Polygone(const vector<Vecteur2D>& points, const string& color = "black");

    void draw() const override;
    double calculateArea() const override;
    string toString() const override;
};

#endif // POLYGONE_H

