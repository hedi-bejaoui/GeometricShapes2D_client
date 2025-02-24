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


    const std::vector<Vecteur2D>& getPoints() const {
        return points;
    }


    void translate(const Vecteur2D& translationVector) override;
    void homothetie(const Vecteur2D& center, double scale) override;
    void rotate(const Vecteur2D& center, double angle) override;



    void draw(const Visiteur *v) const override {
        v->visit(*this);
    }
    void save(const Visiteur *v) const override {
        v->visit(*this);
    }

    double calculateArea() const override;
    string toString() const override;
};

#endif // POLYGONE_H

