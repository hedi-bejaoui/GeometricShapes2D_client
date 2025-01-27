//
// Created by bejaoui on 12/25/2024.
//

#include "Cercle.h"
#include "TCPClient.h"
#include <sstream>
#include <stdexcept>
#include <cmath>

Cercle::Cercle(const Vecteur2D& center, double radius, const string& color)
    : Forme(color), center(center), radius(radius) {
    if (radius <= 0)
        throw invalid_argument("Radius must be positive.");
}





/*void Cercle::draw() const {
    TCPClient client;
    client.connect("127.0.0.1", 8080);

    std::ostringstream request;
    request << "DRAW CIRCLE " << center.x << " " << center.y << " " << radius << " " << color << "\n";
    client.send(request.str());

    client.disconnect();
}*/

double Cercle::calculateArea() const {
    return M_PI * radius * radius;
}

string Cercle::toString() const {
    ostringstream oss;
    oss << "Cercle: center " << string(center) << ", radius " << radius << ", color: " << color;
    return oss.str();
}

void Cercle::translate(const Vecteur2D& translationVector) {
    center += translationVector;
}

void Cercle::homothetie(const Vecteur2D& centerPoint, double scale) {
    center = centerPoint + (center - centerPoint) * scale;
    radius *= scale;
}

void Cercle::rotate(const Vecteur2D& centerPoint, double angle) {
    double cosTheta = cos(angle);
    double sinTheta = sin(angle);
    Vecteur2D relative = center - centerPoint;
    center = centerPoint + Vecteur2D(
        relative.x * cosTheta - relative.y * sinTheta,
        relative.x * sinTheta + relative.y * cosTheta
    );
}

void Cercle::save(std::ostream& out) const {
    out << "CIRCLE " << center.x << " " << center.y << " " << radius << " " << color << "\n";
}
