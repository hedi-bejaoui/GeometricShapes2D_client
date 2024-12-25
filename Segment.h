//
// Created by bejaoui on 12/25/2024.
//

#ifndef SEGMENT_H
#define SEGMENT_H

#include "Forme.h"
#include "Vecteur2D.h"

/** Segment class */
class Segment : public Forme {
    Vecteur2D p1, p2;

public:
    Segment(const Vecteur2D& p1, const Vecteur2D& p2, const string& color = "black");

    void draw() const override;
    double calculateArea() const override;
    string toString() const override;
};

#endif // SEGMENT_H
