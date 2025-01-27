//
// Created by bejaoui on 12/25/2024.
//

#include "Groupe.h"
#include <sstream>
#include <stdexcept>

Groupe::Groupe(const string& color) : Forme(color) {}

void Groupe::addForme(const shared_ptr<Forme>& forme) {
    if (forme->hasParentGroup()) {
        throw logic_error("This form already belongs to another group.");
    }
    forme->setParentGroup(this);
    formes.push_back(forme);
}

vector<shared_ptr<Forme>> Groupe::getFormes() const{
    return formes;
}

double Groupe::calculateArea() const {
    double totalArea = 0;
    for (const auto& forme : formes) {
        totalArea += forme->calculateArea();
    }
    return totalArea;
}

string Groupe::toString() const {
    ostringstream oss;
    oss << "Groupe: [";
    for (const auto& forme : formes) {
        oss << forme->toString() << " ";
    }
    oss << "], color: " << color;
    return oss.str();
}

void Groupe::translate(const Vecteur2D& translationVector) {
    for (auto& forme : formes) {
        forme->translate(translationVector);
    }
}

void Groupe::homothetie(const Vecteur2D& center, double scale) {
    for (auto& forme : formes) {
        forme->homothetie(center, scale);
    }
}

void Groupe::rotate(const Vecteur2D& center, double angle) {
    for (auto& forme : formes) {
        forme->rotate(center, angle);
    }
}


void Groupe::save(std::ostream& out) const {
    out << "GROUP " << color << " [\n";
    for (const auto& forme : formes) {
        forme->save(out); // Delegate saving to child shapes
    }
    out << "]\n";
}




/*void Groupe::draw() const {
    for (const auto& forme : formes) {
        forme->draw();
    }
}*/