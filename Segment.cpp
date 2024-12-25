//
// Created by bejaoui on 12/25/2024.
//

#include "Segment.h"
#include <sstream>

Segment::Segment(const Vecteur2D& p1, const Vecteur2D& p2, const string& color)
    : Forme(color), p1(p1), p2(p2) {}

void Segment::draw() const {
    // Implementation for drawing a segment
}

double Segment::calculateArea() const {
    return 0; // A segment has no area
}

string Segment::toString() const {
    ostringstream oss;
    oss << "Segment: " << string(p1) << " to " << string(p2) << ", color: " << color;
    return oss.str();
}
