//
// Created by geffe on 24/02/2025.
//

#ifndef POLYGONEPARSERCOR_H
#define POLYGONEPARSERCOR_H

#include "formeParserCOR.h"
#include "Polygone.h"
#include <regex>
#include <iostream>
#include <sstream>

class PolygoneParserCOR : public formeParserCOR{
public:
    Forme* parse(const string& ligne) override {
        cout << "Tentative de parsing : " << ligne << endl;

        // Expression régulière pour extraire les sommets et la couleur finale
        regex polygoneRegex(R"(Polygone: ((?:\(\d+, \d+, color: \w+\) )+), color: (\w+))");
        smatch matches;

        if (regex_search(ligne, matches, polygoneRegex)) {
            if (matches.size() == 3) { // 1 pour les sommets, 1 pour la couleur
                string pointsStr = matches[1]; // Liste des sommets
                string color = matches[2]; // Couleur finale

                vector<Vecteur2D> points;
                regex pointRegex(R"(\((\d+), (\d+), color: \w+\))");
                smatch pointMatches;
                string::const_iterator searchStart(pointsStr.cbegin());

                // Extraction des sommets
                while (regex_search(searchStart, pointsStr.cend(), pointMatches, pointRegex)) {
                    double x = stod(pointMatches[1]);
                    double y = stod(pointMatches[2]);
                    points.emplace_back(x, y);
                    searchStart = pointMatches.suffix().first;
                }

                cout << "Polygone reconnu avec " << points.size() << " sommets, Couleur=" << color << endl;

                return new Polygone(points, color);
            }
        }

        cout << "Ligne non reconnue par PolygoneParser." << endl;
        return formeParserCOR::parse(ligne);
    }
};



#endif //POLYGONEPARSERCOR_H
