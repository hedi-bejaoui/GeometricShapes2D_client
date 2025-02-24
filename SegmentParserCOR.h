//
// Created by geffe on 24/02/2025.
//

#ifndef SEGMENTPARSERCOR_H
#define SEGMENTPARSERCOR_H

#include "formeParserCOR.h"
#include "Segment.h"
#include <regex>
#include <iostream>


class SegmentParserCOR : public formeParserCOR{
public:
    Forme* parse(const string& ligne) override {
        cout << "Tentative de parsing : " << ligne << endl;

        // Expression régulière pour extraire les points et la couleur
        regex segmentRegex(R"(Segment: \((\d+), (\d+), color: \w+\) to \((\d+), (\d+), color: \w+\), color: (\w+))");
        smatch matches;

        if (regex_search(ligne, matches, segmentRegex)) {
            if (matches.size() == 6) { // 2 points + couleur finale
                double x1 = stod(matches[1]);
                double y1 = stod(matches[2]);
                double x2 = stod(matches[3]);
                double y2 = stod(matches[4]);
                string color = matches[5]; // Couleur finale du segment

                cout << "Segment reconnu avec Points=("
                     << x1 << "," << y1 << ") to ("
                     << x2 << "," << y2 << "), Couleur=" << color << endl;

                return new Segment(Vecteur2D(x1, y1), Vecteur2D(x2, y2), color);
            }
        }

        cout << "Ligne non reconnue par SegmentParser." << endl;
        return formeParserCOR::parse(ligne);
    }
};



#endif //SEGMENTPARSERCOR_H
