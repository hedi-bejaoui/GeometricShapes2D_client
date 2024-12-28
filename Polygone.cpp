//
// Created by bejaoui on 12/25/2024.
//

#include "Polygone.h"
#include "TCPClient.h"
#include <sstream>
#include <stdexcept>
#include <cmath>

Polygone::Polygone(const vector<Vecteur2D>& points, const string& color)
    : Forme(color), points(points) {
    if (points.size() < 3)
        throw invalid_argument("A polygon must have at least three points.");
}

void Polygone::draw() const {
    TCPClient client;
    client.connect("127.0.0.1", 8080);

    std::ostringstream request;
    request << "DRAW POLYGONE";
    for (const auto& point : points) {
        request << " " << point.x << " " << point.y;
    }
    request << " " << color << "\n";
    client.send(request.str());

    client.disconnect();
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

void Polygone::translate(const Vecteur2D& translationVector) {
    for (auto& point : points) {
        point += translationVector;
    }
}

void Polygone::homothetie(const Vecteur2D& center, double scale) {
    for (auto& point : points) {
        point = center + (point - center) * scale;
    }
}

void Polygone::rotate(const Vecteur2D& center, double angle) {
    double cosTheta = cos(angle);
    double sinTheta = sin(angle);
    for (auto& point : points) {
        Vecteur2D relative = point - center;
        point = center + Vecteur2D(
            relative.x * cosTheta - relative.y * sinTheta,
            relative.x * sinTheta + relative.y * cosTheta
        );
    }
}

void Polygone::save(std::ostream& out) const {
    out << "POLYGONE " << points.size();
    for (const auto& point : points) {
        out << " (" << point.x << " " << point.y << ")";
    }
    out << " " << color << "\n";
}
