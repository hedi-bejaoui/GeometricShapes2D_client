//
// Created by bejaoui on 12/25/2024.
//

#ifndef CERCLE_H
#define CERCLE_H

#include "Forme.h"
#include "Vecteur2D.h"

//class Visiteur;

/** Cercle class */
class Cercle : public Forme {
public:
    Vecteur2D center;
    double radius;

    Cercle(const Vecteur2D& center, double radius, const string& color = "black");

    void translate(const Vecteur2D& translationVector) override;
    void homothetie(const Vecteur2D& centerPoint, double scale) override;
    void rotate(const Vecteur2D& centerPoint, double angle) override;

    void save(std::ostream &out) const override;



    void draw(const Visiteur *v) const override {
        v->visit(*this);
    }




    double calculateArea() const override;
    string toString() const override;
};

#include "Visteur.h"

#endif // CERCLE_H

