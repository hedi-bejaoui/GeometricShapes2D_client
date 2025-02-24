//
// Created by geffe on 24/02/2025.
//

#ifndef CERCLEPARSER_H
#define CERCLEPARSER_H

#include <iostream>

#include "formeParserCOR.h"
#include "Cercle.h"
#include <sstream>
#include <regex>

class CercleParserCOR :public formeParserCOR{
public:
    Forme* parse(const string& ligne) override {
        cout << "Tentative de parsing : " << ligne << endl;

        // Expression régulière pour extraire les données du cercle
        regex cercleRegex(R"(Cercle: center \((\d+), (\d+), color: (\w+)\), radius (\d+), color: (\w+))");
        smatch matches;

        if (regex_search(ligne, matches, cercleRegex)) {
            if (matches.size() == 6) {
                double x = stod(matches[1]);
                double y = stod(matches[2]);
                string color1 = matches[3]; // Première couleur (color: black)
                double rayon = stod(matches[4]);
                string color2 = matches[5]; // Couleur finale (color: red)

                cout << "Cercle reconnu avec x=" << x << ", y=" << y
                     << ", r=" << rayon << ", couleur=" << color2 << endl;

                return new Cercle(Vecteur2D(x, y), rayon, color2);
            }
        }

        cout << "Ligne non reconnue par CercleParser." << endl;
        return formeParserCOR::parse(ligne);
    }

};



#endif //CERCLEPARSER_H
