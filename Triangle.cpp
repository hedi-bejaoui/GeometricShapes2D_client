//
// Created by bejaoui on 12/25/2024.
//

#include "Triangle.h"
#include "TCPClient.h"
#include <sstream>
#include <cmath>

Triangle::Triangle(const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3, const string& color)
    : Forme(color), p1(p1), p2(p2), p3(p3) {}

Triangle::Triangle(const Triangle &tri) {
    this->p1 = tri.p1;
    this->p2 = tri.p2;
    this->p3 = tri.p3;
}

Vecteur2D Triangle::getP1() const {
    return this->p1;
}
Vecteur2D Triangle::getP2() const {
    return this->p2;
}
Vecteur2D Triangle::getP3() const {
    return this->p3;
}


double Triangle::calculateArea() const {
    return 0.5 * abs((p2 - p1).det(p3 - p1));
}

string Triangle::toString() const {
    ostringstream oss;
    oss << "Triangle: " << string(p1) << ", " << string(p2) << ", " << string(p3) << ", color: " << color;
    return oss.str();
}

void Triangle::translate(const Vecteur2D& translationVector) {
    p1 += translationVector;
    p2 += translationVector;
    p3 += translationVector;
}

void Triangle::homothetie(const Vecteur2D& center, double scale) {
    p1 = center + (p1 - center) * scale;
    p2 = center + (p2 - center) * scale;
    p3 = center + (p3 - center) * scale;
}

void Triangle::rotate(const Vecteur2D& center, double angle) {
    auto rotatePoint = [&](Vecteur2D& point) {
        double cosTheta = cos(angle);
        double sinTheta = sin(angle);
        Vecteur2D relative = point - center;
        point = center + Vecteur2D(
            relative.x * cosTheta - relative.y * sinTheta,
            relative.x * sinTheta + relative.y * cosTheta
        );
    };

    rotatePoint(p1);
    rotatePoint(p2);
    rotatePoint(p3);
}

