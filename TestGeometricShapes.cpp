//
// Created by bejaoui on 12/25/2024.
//

#include <iostream>
#include <memory>
#include "Vecteur2D.h"
#include "Forme.h"
#include "Segment.h"
#include "Cercle.h"
#include "Triangle.h"
#include "Polygone.h"
#include "Groupe.h"

using namespace std;

void testColorValidation() {
    cout << "Testing color validation..." << endl;

    try {
        Segment s1(Vecteur2D(0, 0), Vecteur2D(1, 1), "blue");
        cout << "Segment created successfully with color 'blue'." << endl;

        Segment s2(Vecteur2D(0, 0), Vecteur2D(1, 1), "orange");
        cout << "ERROR: Segment created with invalid color 'orange'." << endl;
    } catch (const invalid_argument& e) {
        cout << "Caught expected exception: " << e.what() << endl;
    }
}

void testSimpleShapes() {
    cout << "\nTesting simple shapes..." << endl;

    // Segment
    Segment s(Vecteur2D(0, 0), Vecteur2D(2, 2), "red");
    cout << s.toString() << endl;

    // Circle
    Cercle c(Vecteur2D(0, 0), 5, "green");
    cout << c.toString() << endl;
    cout << "Area of circle: " << c.calculateArea() << endl;

    // Triangle
    Triangle t(Vecteur2D(0, 0), Vecteur2D(4, 0), Vecteur2D(0, 3), "yellow");
    cout << t.toString() << endl;
    cout << "Area of triangle: " << t.calculateArea() << endl;

    // Polygon
    vector<Vecteur2D> points = {Vecteur2D(0, 0), Vecteur2D(4, 0), Vecteur2D(4, 3), Vecteur2D(0, 3)};
    Polygone p(points, "cyan");
    cout << p.toString() << endl;
    cout << "Area of polygon: " << p.calculateArea() << endl;
}

void testGroups() {
    cout << "\nTesting groups..." << endl;

    auto segment = make_shared<Segment>(Vecteur2D(0, 0), Vecteur2D(2, 2), "red");
    auto circle = make_shared<Cercle>(Vecteur2D(1, 1), 3, "blue");

    Groupe group1("yellow");
    group1.addForme(segment);
    group1.addForme(circle);

    cout << group1.toString() << endl;
    cout << "Area of group1: " << group1.calculateArea() << endl;

    // Attempt to add the same shape to another group
    Groupe group2("green");
    try {
        group2.addForme(segment);
        cout << "ERROR: Shape added to multiple groups." << endl;
    } catch (const logic_error& e) {
        cout << "Caught expected exception: " << e.what() << endl;
    }
}

void testInvalidPolygons() {
    cout << "\nTesting invalid polygons..." << endl;

    try {
        vector<Vecteur2D> invalidPoints = {Vecteur2D(0, 0), Vecteur2D(1, 1)};
        Polygone invalidPolygon(invalidPoints, "black");
        cout << "ERROR: Polygon created with fewer than 3 points." << endl;
    } catch (const invalid_argument& e) {
        cout << "Caught expected exception: " << e.what() << endl;
    }
}

int main() {
    cout << "Starting geometric shapes tests..." << endl;

    testColorValidation();
    testSimpleShapes();
    testGroups();
    testInvalidPolygons();

    cout << "\nAll tests completed." << endl;

    return 0;
}
