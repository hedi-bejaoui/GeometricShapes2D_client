//
// Created by bejaoui on 12/25/2024.
//

#include "Segment.h"
#include "TCPClient.h"
#include <sstream>

Segment::Segment(const Vecteur2D& p1, const Vecteur2D& p2, const string& color)
    : Forme(color), p1(p1), p2(p2) {}

void Segment::draw() const {
    TCPClient client;
    client.connect("127.0.0.1", 8080);

    std::ostringstream request;
    request << "DRAW SEGMENT " << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << " " << color << "\n";
    client.send(request.str());

    client.disconnect();
}

double Segment::calculateArea() const {
    return 0; // A segment has no area
}

string Segment::toString() const {
    ostringstream oss;
    oss << "Segment: " << string(p1) << " to " << string(p2) << ", color: " << color;
    return oss.str();
}

void Segment::translate(const Vecteur2D& translationVector) {
    p1 += translationVector;
    p2 += translationVector;
}

void Segment::homothetie(const Vecteur2D& center, double scale) {
    p1 = center + (p1 - center) * scale;
    p2 = center + (p2 - center) * scale;
}

void Segment::rotate(const Vecteur2D& center, double angle) {
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
}

void Segment::save(std::ostream& out) const {
    out << "SEGMENT " << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << " " << color << "\n";
}
