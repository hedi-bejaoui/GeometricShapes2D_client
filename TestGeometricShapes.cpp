//
// Created by bejaoui on 12/25/2024.
//

#include <iostream>
#include <memory>
#include <cmath>
#include "Segment.h"
#include "Cercle.h"
#include "Triangle.h"
#include "Polygone.h"
#include "Groupe.h"
#include "Translation.h"
#include "Homothetie.h"
#include "Rotation.h"
#include <fstream>

#include "formeFactoryCOR.h"
#include "VisiteurEnregistrer.h"
#include "VisteurDessinerJAVA.h"

using namespace std;
/*
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
*/


/*
int main() {
    cout << "Starting geometric shapes tests..." << endl;

    testColorValidation();
    testSimpleShapes();
    testGroups();
    testInvalidPolygons();

    cout << "\nAll tests completed." << endl;

    return 0;
}
*/
/*
// Helper function to compare two double values for approximate equality
bool areEqual(double a, double b, double epsilon = 1e-6) {
    return fabs(a - b) < epsilon;
}

void testTranslation() {
    cout << "Testing Translation..." << endl;

    // Create shapes
    Segment segment(Vecteur2D(0, 0), Vecteur2D(1, 1), "red");
    Cercle circle(Vecteur2D(2, 2), 1, "blue");
    Triangle triangle(Vecteur2D(0, 0), Vecteur2D(3, 0), Vecteur2D(0, 4), "yellow");

    vector<Vecteur2D> points = {Vecteur2D(0, 0), Vecteur2D(2, 0), Vecteur2D(1, 1)};
    Polygone polygon(points, "green");

    Groupe group("cyan");
    group.addForme(make_shared<Segment>(segment));
    group.addForme(make_shared<Cercle>(circle));
    group.addForme(make_shared<Triangle>(triangle));
    group.addForme(make_shared<Polygone>(polygon));

    // Apply translation
    Translation translation(Vecteur2D(2, 2));
    translation.apply(group);

    // Output results
    cout << "Translated Group:\n" << group.toString() << endl;

    // Check results
    cout << "Translation test completed successfully!" << endl;
}

void testHomothetie() {
    cout << "\nTesting Homothetie..." << endl;

    // Create shapes
    Segment segment(Vecteur2D(1, 1), Vecteur2D(2, 2), "red");
    Cercle circle(Vecteur2D(3, 3), 1, "blue");
    Triangle triangle(Vecteur2D(0, 0), Vecteur2D(4, 0), Vecteur2D(0, 3), "yellow");

    vector<Vecteur2D> points = {Vecteur2D(0, 0), Vecteur2D(3, 0), Vecteur2D(1.5, 1.5)};
    Polygone polygon(points, "green");

    Groupe group("cyan");
    group.addForme(make_shared<Segment>(segment));
    group.addForme(make_shared<Cercle>(circle));
    group.addForme(make_shared<Triangle>(triangle));
    group.addForme(make_shared<Polygone>(polygon));

    // Apply homothetie
    Homothetie homothetie(Vecteur2D(1, 1), 2.0);
    homothetie.apply(group);

    // Output results
    cout << "Scaled Group:\n" << group.toString() << endl;

    // Check results
    cout << "Homothetie test completed successfully!" << endl;
}

void testRotation() {
    cout << "\nTesting Rotation..." << endl;

    // Create shapes
    Segment segment(Vecteur2D(1, 1), Vecteur2D(2, 2), "red");
    Cercle circle(Vecteur2D(3, 3), 1, "blue");
    Triangle triangle(Vecteur2D(0, 0), Vecteur2D(4, 0), Vecteur2D(0, 3), "yellow");

    vector<Vecteur2D> points = {Vecteur2D(0, 0), Vecteur2D(3, 0), Vecteur2D(1.5, 1.5)};
    Polygone polygon(points, "green");

    Groupe group("cyan");
    group.addForme(make_shared<Segment>(segment));
    group.addForme(make_shared<Cercle>(circle));
    group.addForme(make_shared<Triangle>(triangle));
    group.addForme(make_shared<Polygone>(polygon));

    // Apply rotation
    Rotation rotation(Vecteur2D(1, 1), M_PI / 4); // Rotate by 45 degrees
    rotation.apply(group);

    // Output results
    cout << "Rotated Group:\n" << group.toString() << endl;

    // Check results
    cout << "Rotation test completed successfully!" << endl;
}

void testGroupTranslation() {
    cout << "Testing Group Translation..." << endl;

    // Create shapes
    auto segment = make_shared<Segment>(Vecteur2D(0, 0), Vecteur2D(1, 1), "red");
    auto circle = make_shared<Cercle>(Vecteur2D(2, 2), 1, "blue");
    auto triangle = make_shared<Triangle>(Vecteur2D(0, 0), Vecteur2D(3, 0), Vecteur2D(0, 4), "yellow");

    Groupe subgroup("green");
    subgroup.addForme(segment);
    subgroup.addForme(circle);

    Groupe mainGroup("cyan");
    mainGroup.addForme(make_shared<Groupe>(subgroup)); // Add subgroup
    mainGroup.addForme(triangle);

    // Apply translation
    Translation translation(Vecteur2D(2, 2));
    translation.apply(mainGroup);

    // Output results
    cout << "Translated Main Group:\n" << mainGroup.toString() << endl;
}

void testGroupHomothetie() {
    cout << "\nTesting Group Homothetie..." << endl;

    // Create shapes
    auto segment = make_shared<Segment>(Vecteur2D(1, 1), Vecteur2D(2, 2), "red");
    auto circle = make_shared<Cercle>(Vecteur2D(3, 3), 1, "blue");
    auto triangle = make_shared<Triangle>(Vecteur2D(0, 0), Vecteur2D(4, 0), Vecteur2D(0, 3), "yellow");

    Groupe subgroup("green");
    subgroup.addForme(segment);
    subgroup.addForme(circle);

    Groupe mainGroup("cyan");
    mainGroup.addForme(make_shared<Groupe>(subgroup)); // Add subgroup
    mainGroup.addForme(triangle);

    // Apply homothetie
    Homothetie homothetie(Vecteur2D(1, 1), 2.0);
    homothetie.apply(mainGroup);

    // Output results
    cout << "Scaled Main Group:\n" << mainGroup.toString() << endl;
}

void testGroupRotation() {
    cout << "\nTesting Group Rotation..." << endl;

    // Create shapes
    auto segment = make_shared<Segment>(Vecteur2D(1, 1), Vecteur2D(2, 2), "red");
    auto circle = make_shared<Cercle>(Vecteur2D(3, 3), 1, "blue");
    auto triangle = make_shared<Triangle>(Vecteur2D(0, 0), Vecteur2D(4, 0), Vecteur2D(0, 3), "yellow");

    Groupe subgroup("green");
    subgroup.addForme(segment);
    subgroup.addForme(circle);

    Groupe mainGroup("cyan");
    mainGroup.addForme(make_shared<Groupe>(subgroup)); // Add subgroup
    mainGroup.addForme(triangle);

    // Apply rotation
    Rotation rotation(Vecteur2D(1, 1), M_PI / 4); // Rotate by 45 degrees
    rotation.apply(mainGroup);

    // Output results
    cout << "Rotated Main Group:\n" << mainGroup.toString() << endl;
}
*/

/*
int main() {
    cout << "Starting geometric transformations tests on groups..." << endl;

    testGroupTranslation();
    testGroupHomothetie();
    testGroupRotation();

    cout << "\nAll group tests completed successfully!" << endl;
    return 0;
}
*/


// test pour sauvegarder une forme, triangle.....
int main() {

    /*****************************************************************___Test_Sauvegarde_Lectures_fichier_txt___*********************************************************************************/
    {
        /**
        * Convention d'écriture/lecture dans un fichier
        *
        * Pour le cercle         Cercle: center (..., ..., color: ...), radius ..., color: ...
        * Pour un triangle       Triangle: (..., ..., color: ...), (..., ..., color: ...), (..., ..., color: ...), color: ...
        * Pour un segment        Segment: (..., ..., color: ...) to (..., ..., color: ...), color: ...
        * Pour un polygone       Polygone: (..., ..., color: ...) (..., ..., color: ...) (..., ..., color: ...) ......nbPoint...... , color: ...
        */

        try {

            //sauvegarde de forme dans leurs fichiers respectifs ( class c ++ vers string) :

            cout << "************************************************************************************************************************************" << endl;
            VisiteurEnregistrer visiteur;
            Triangle triangle(Vecteur2D(400, 400), Vecteur2D(450, 500), Vecteur2D(350, 450), "blue");
            triangle.save(&visiteur);
            Cercle circle(Vecteur2D(100, 100), 50, "red");
            circle.save(&visiteur);
            Segment segment(Vecteur2D(200, 200), Vecteur2D(300, 300), "green");
            segment.save(&visiteur);
            std::vector<Vecteur2D> points = {Vecteur2D(500, 500), Vecteur2D(550, 550), Vecteur2D(600, 500), Vecteur2D(550, 450)};
            Polygone polygon(points, "yellow");
            polygon.save(&visiteur);

            Groupe groupe("black");
            groupe.addForme(make_shared<Cercle>(circle));
            groupe.addForme(make_shared<Segment>(segment));
            groupe.addForme(make_shared<Triangle>(triangle));
            groupe.addForme(make_shared<Polygone>(polygon));

            // Sauvegarde tout le groupe avec toutes ses formes :
            groupe.save(&visiteur);



            // Lecture de forme dans des fichiers ( string vers class c ++ )
            cout << "************************************************************************************************************************************" << endl;
            /*vector<Forme*> formes = formeFactoryCOR::chargerDepuisFichier("../lecture/forme.txt");

            for (Forme* forme : formes) {
                cout << "Forme chargée: " << forme->toString() << endl;
                delete forme; // Nettoyage mémoire
            }*/

        } catch (const std::exception& e) {
            std::cout << "c'est problématique" << std::endl;
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    /*****************************************************************___Test_Dessin_Formes_Vers_serveur_JAVA___*********************************************************************************/
    {
        try {
            cout << "************************************************************************************************************************************" << endl;
            VisiteurDessinerJAVA visiteur;
            // Create and draw shapes
           Cercle circle(Vecteur2D(100, 100), 50, "red"); // Red circle
            circle.draw(&visiteur);

            Segment segment(Vecteur2D(200, 200), Vecteur2D(300, 300), "green"); // Green segment
            segment.draw(&visiteur);

            Triangle triangle(Vecteur2D(400, 400), Vecteur2D(450, 500), Vecteur2D(350, 450), "blue"); // Blue triangle
            triangle.draw(&visiteur);

            std::vector<Vecteur2D> points = {Vecteur2D(500, 600), Vecteur2D(850, 550), Vecteur2D(200, 500), Vecteur2D(550, 450)};
            Polygone polygon(points, "black"); // Yellow polygon
            polygon.draw(&visiteur);

            // ou avec Formes
            Groupe groupe("red");
            groupe.addForme(make_shared<Cercle>(Vecteur2D(100, 100), 50, "red"));
            groupe.addForme(make_shared<Segment>(Vecteur2D(200, 200), Vecteur2D(300, 300), "green"));
            groupe.addForme(make_shared<Triangle>(Vecteur2D(400, 400), Vecteur2D(450, 500), Vecteur2D(350, 450), "blue"));
            groupe.addForme(make_shared<Polygone>(points, "yellow"));

            groupe.draw(&visiteur);



            std::cout << "All shapes drawn successfully." << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

}




/*int main() {
    // Create shapes
    auto circle = std::make_shared<Cercle>(Vecteur2D(100, 100), 50, "red");
    auto segment = std::make_shared<Segment>(Vecteur2D(200, 200), Vecteur2D(300, 300), "green");

    // Create a group
    Groupe group("cyan");
    group.addForme(circle);
    group.addForme(segment);

    // Save shapes to file
    std::ofstream outFile("shapes.txt");
    group.save(outFile);
    outFile.close();

    // Load shapes from file
    std::ifstream inFile("shapes.txt");
    auto loadedGroup = ShapeFactory::load(inFile);
    inFile.close();

    // Display loaded shapes
    std::cout << loadedGroup->toString() << std::endl;

    return 0;
}*/