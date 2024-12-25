//
// Created by bejaoui on 12/25/2024.
//

#include "Triangle.h"
#include <sstream>
#include <cmath>

Triangle::Triangle(const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3, const string& color)
    : Forme(color), p1(p1), p2(p2), p3(p3) {}

void Triangle::draw() const {
    // Implementation for drawing a triangle
}

double Triangle::calculateArea() const {
    return 0.5 * abs((p2 - p1).det(p3 - p1));
}

string Triangle::toString() const {
    ostringstream oss;
    oss << "Triangle: " << string(p1) << ", " << string(p2) << ", " << string(p3) << ", color: " << color;
    return oss.str();
}

