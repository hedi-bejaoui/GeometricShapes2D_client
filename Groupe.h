//
// Created by bejaoui on 12/25/2024.
//

#ifndef GROUPE_H
#define GROUPE_H

#include "Forme.h"
#include <vector>
#include <memory>
#include "Visteur.h"



/** Groupe class */
class Groupe : public Forme {
    vector<shared_ptr<Forme>> formes;

public:
    Groupe(const string& color = "black");

    vector<shared_ptr<Forme>> getFormes()const;

    void addForme(const shared_ptr<Forme>& forme);

    void translate(const Vecteur2D& translationVector) override;
    void homothetie(const Vecteur2D& center, double scale) override;
    void rotate(const Vecteur2D& center, double angle) override;

    void save(std::ostream &out) const override;

    double calculateArea() const override;
    string toString() const override;


    void draw(const Visiteur *v) const override {
        v->visit(*this);
    }
};

#endif // GROUPE_H
