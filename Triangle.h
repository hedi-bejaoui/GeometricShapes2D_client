//
// Created by bejaoui on 12/25/2024.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Forme.h"
#include "Vecteur2D.h"

/** Triangle class */
class Triangle : public Forme {
    Vecteur2D p1, p2, p3;

public:
    Triangle(const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3, const string& color = "black");

    void draw() const override;
    double calculateArea() const override;
    string toString() const override;
};

#endif // TRIANGLE_H

