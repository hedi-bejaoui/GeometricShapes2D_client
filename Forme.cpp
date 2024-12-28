//
// Created by bejaoui on 12/25/2024.
//

#include "Forme.h"
#include "Vecteur2D.h"
#include "Transformation.h"

Forme::Forme(const string& color) : color(Vecteur2D::validateColor(color)), parentGroup(nullptr) {}
Forme::~Forme() {}

const string& Forme::getColor() const {
    return color;
}

void Forme::setParentGroup(const Groupe* group) {
    if (parentGroup != nullptr) {
        throw logic_error("This form already belongs to another group.");
    }
    parentGroup = group;
}

bool Forme::hasParentGroup() const {
    return parentGroup != nullptr;
}


