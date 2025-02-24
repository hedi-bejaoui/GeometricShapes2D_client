//
// Created by geffe on 24/02/2025.
//

#ifndef TRIANGLEPARSER_H
#define TRIANGLEPARSER_H
#include "formeParserCOR.h"
#include "Triangle.h"
#include <regex>
#include <iostream>


class TriangleParserCOR : public formeParserCOR{
public:
    Forme* parse(const string& ligne) override {
        cout << "Tentative de parsing : " << ligne << endl;

        // Expression régulière pour extraire les sommets et la couleur
        regex triangleRegex(R"(Triangle: \((\d+), (\d+), color: \w+\), \((\d+), (\d+), color: \w+\), \((\d+), (\d+), color: \w+\), color: (\w+))");
        smatch matches;

        if (regex_search(ligne, matches, triangleRegex)) {
            if (matches.size() == 8) { // 3 sommets + couleur finale
                double x1 = stod(matches[1]);
                double y1 = stod(matches[2]);
                double x2 = stod(matches[3]);
                double y2 = stod(matches[4]);
                double x3 = stod(matches[5]);
                double y3 = stod(matches[6]);
                string color = matches[7]; // Couleur finale du triangle

                cout << "Triangle reconnu avec Sommets=("
                     << x1 << "," << y1 << "), ("
                     << x2 << "," << y2 << "), ("
                     << x3 << "," << y3 << "), Couleur=" << color << endl;

                return new Triangle(Vecteur2D(x1, y1), Vecteur2D(x2, y2), Vecteur2D(x3, y3), color);
            }
        }

        cout << "Ligne non reconnue par TriangleParser." << endl;
        return formeParserCOR::parse(ligne);
    }
};



#endif //TRIANGLEPARSER_H
