#ifndef GROUPEPARSER_H
#define GROUPEPARSER_H

#include <iostream>
#include <sstream>
#include <regex>

#include "formeParserCOR.h"
#include "Groupe.h"

class GroupeParserCOR : public formeParserCOR {
public:
    Forme* parse(const string& ligne) override {
        cout << "Tentative de parsing du groupe : " << ligne << endl;

        // Expression régulière pour détecter un groupe avec sa couleur
        regex groupeRegex(R"(Groupe: color (\w+))");
        smatch matches;

        if (regex_search(ligne, matches, groupeRegex)) {
            if (matches.size() == 2) {
                string color = matches[1]; // Récupération de la couleur du groupe
                cout << "Groupe reconnu avec couleur = " << color << endl;

                auto* groupe = new Groupe(color);

                // Lire les formes contenues dans le groupe
                string subLigne;
                while (getline(cin, subLigne) && subLigne != "END_GROUPE") { // Supposons une fin de groupe marquée par "END_GROUPE"
                    Forme* forme = formeParserCOR::parse(subLigne); // Utilise les autres parsers
                    if (forme) {
                        groupe->addForme(shared_ptr<Forme>(forme));
                    }
                }

                return groupe;
            }
        }

        cout << "Ligne non reconnue par GroupeParser." << endl;
        return formeParserCOR::parse(ligne);
    }
};

#endif // GROUPEPARSER_H
