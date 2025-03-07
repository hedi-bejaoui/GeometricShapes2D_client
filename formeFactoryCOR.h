/**
 * @file FormeFactoryCOR.h
 * @brief Declaration of the formeFactoryCOR class for loading shapes from a file.
 *
 * This file defines the formeFactoryCOR class that uses the Chain of Responsibility pattern
 * to parse a file containing shape representations. It creates a chain of shape parsers and processes
 * each line in the file to convert it into a Forme object.
 */

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
#include "InputStreamProvider.h"

using namespace std;

/**
 * @class formeFactoryCOR
 * @brief Factory class for loading shapes using the Chain of Responsibility pattern.
 *
 * The formeFactoryCOR class provides a static method to load shapes from a text file. It builds a
 * chain of shape parsers and processes each line in the file, converting recognized shape representations
 * into Forme objects. Unrecognized lines are reported via console output.
 */
class formeFactoryCOR {
public:
    /**
     * @brief Loads shapes from a specified file.
     * @param filename The path to the file containing shape representations.
     * @return A vector of pointers to Forme objects that have been successfully parsed.
     *
     * This method opens the file specified by @p filename, creates a chain of shape parsers, and processes
     * each line of the file. If a line is successfully parsed into a Forme object, the object is added to the
     * returned vector. If the file cannot be opened, an error message is printed and an empty vector is returned.
     */
    static vector<Forme*> chargerDepuisFichier(const string& filename) {
        ifstream file(filename);
        currentInputStream = &file; // Set the global pointer to the file stream
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

#endif // FORMEFACTORYCOR_H
