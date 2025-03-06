//
// Created by geffe on 24/02/2025.
//

#ifndef FORMEFACTORYCOR_H
#define FORMEFACTORYCOR_H
#include <iostream>
#include <fstream>
#include <vector>

#include "CercleParserCOR.h"
#include "formeParserCOR.h"
#include "GroupeParserCOR.h"
#include "PolygoneParserCOR.h"
#include "SegmentParserCOR.h"
#include "TriangleParserCOR.h"

using namespace std;

class formeFactoryCOR {
public:
    static vector<Forme*> chargerDepuisFichier(const string& filename) {
        ifstream file(filename);
        vector<Forme*> formes;

        if (!file) {
            cerr << "Erreur: Impossible d'ouvrir " << filename << endl;
            return formes;
        }

        cout << "Fichier ouvert avec succes : " << filename << endl;

        // Création de la chaîne de responsabilité
        GroupeParserCOR groupeParser;
        CercleParserCOR cercleParser;
        TriangleParserCOR triangleParser;
        PolygoneParserCOR polygoneParser;
        SegmentParserCOR segmentParser;

        // Chaînage des parsers
        groupeParser.setNext(&cercleParser);
        cercleParser.setNext(&triangleParser);
        triangleParser.setNext(&polygoneParser);
        polygoneParser.setNext(&segmentParser);

        formeParserCOR* firstParser = &groupeParser;


        string ligne;
        while (getline(file, ligne)) {
            cout << "Traitement de la ligne : " << ligne << endl;

            Forme* forme = nullptr;
            if (firstParser) {
                forme = firstParser->parse(ligne); // Vérifie que ce parseur fonctionne
            }

            if (forme) {
                cout << "Forme convertie avec succes ! " << endl;
                formes.push_back(forme);
            } else {
                cout << "Aucun parser n'a reconnu cette ligne." << endl;
            }
        }

        file.close();
        return formes;
    }
};



#endif //FORMEFACTORYCOR_H
