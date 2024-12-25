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

void Groupe::draw() const {
    for (const auto& forme : formes) {
        forme->draw();
    }
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
