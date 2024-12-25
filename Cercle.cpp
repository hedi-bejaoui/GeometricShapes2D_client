//
// Created by bejaoui on 12/25/2024.
//

#include "Cercle.h"
#include <sstream>
#include <stdexcept>
#include <cmath>

Cercle::Cercle(const Vecteur2D& center, double radius, const string& color)
    : Forme(color), center(center), radius(radius) {
    if (radius <= 0)
        throw invalid_argument("Radius must be positive.");
}

void Cercle::draw() const {
    // Implementation for drawing a circle
}

double Cercle::calculateArea() const {
    return M_PI * radius * radius;
}

string Cercle::toString() const {
    ostringstream oss;
    oss << "Cercle: center " << string(center) << ", radius " << radius << ", color: " << color;
    return oss.str();
}

