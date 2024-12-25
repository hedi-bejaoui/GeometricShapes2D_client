//
// Created by bejaoui on 12/25/2024.
//

#include "Polygone.h"
#include <sstream>
#include <stdexcept>
#include <cmath>

Polygone::Polygone(const vector<Vecteur2D>& points, const string& color)
    : Forme(color), points(points) {
    if (points.size() < 3)
        throw invalid_argument("A polygon must have at least three points.");
}

void Polygone::draw() const {
    // Implementation for drawing a polygon
}

double Polygone::calculateArea() const {
    double area = 0;
    for (size_t i = 0; i < points.size(); ++i) {
        const Vecteur2D& current = points[i];
        const Vecteur2D& next = points[(i + 1) % points.size()];
        area += current.det(next);
    }
    return abs(area) / 2.0;
}

string Polygone::toString() const {
    ostringstream oss;
    oss << "Polygone: ";
    for (const auto& point : points) {
        oss << string(point) << " ";
    }
    oss << ", color: " << color;
    return oss.str();
}
