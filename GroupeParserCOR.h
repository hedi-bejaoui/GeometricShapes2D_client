/**
 * @file GroupeParserCOR.h
 * @brief Declaration of the GroupeParserCOR class for parsing group shapes.
 *
 * This file defines the GroupeParserCOR class, which is derived from formeParserCOR. It attempts to
 * parse a string representation of a group shape (Groupe) by detecting its color and then reading
 * subsequent lines (representing the contained shapes) from standard input until an "END_GROUPE" marker is encountered.
 * Parsed shapes are added to the group, and the complete Groupe object is returned.
 */

#ifndef GROUPEPARSER_H
#define GROUPEPARSER_H

#include <iostream>
#include <sstream>
#include <regex>

#include "formeParserCOR.h"
#include "Groupe.h"
#include "InputStreamProvider.h"

/**
 * @class GroupeParserCOR
 * @brief Parses group shapes using the Chain of Responsibility pattern.
 *
 * The GroupeParserCOR class attempts to parse a group (Groupe) from an input string by
 * matching a regular expression that detects a group with its color. If successful, it creates
 * a new Groupe object and reads subsequent lines (using standard input) until "END_GROUPE" is encountered.
 * Each line is parsed using the chain of parsers, and any recognized shape is added to the group.
 * If the input is not recognized as a group, parsing is delegated to the next parser in the chain.
 */
class GroupeParserCOR : public formeParserCOR {
public:
    /**
     * @brief Parses a string into a Groupe object.
     * @param ligne The input string representing a group declaration.
     * @return A pointer to a new Groupe object if the string is recognized; otherwise, delegates parsing to the next parser.
     *
     * This method uses a regular expression to detect a group declaration of the form:
     * "Groupe: color <color>". If matched, it extracts the group color, creates a new Groupe,
     * and then reads additional lines from standard input until "END_GROUPE" is encountered.
     * Each subsequent line is parsed using the chain of responsibility (formeParserCOR::parse)
     * and added to the group. If the group declaration is not recognized, the parsing request
     * is delegated to the next parser in the chain.
     */
    Forme* parse(const std::string& ligne) override {
        std::cout << "Tentative de parsing du groupe : " << ligne << std::endl;

        // Regular expression to detect a group declaration with its color.
        std::regex groupeRegex(R"(Groupe: color (\w+))");
        std::smatch matches;

        if (std::regex_search(ligne, matches, groupeRegex)) {
            if (matches.size() == 2) {
                std::string color = matches[1]; // Retrieve the group's color.
                std::cout << "Groupe reconnu avec couleur = " << color << std::endl;

                auto* groupe = new Groupe(color);

                // Read shapes contained in the group.
                std::string subLigne;
                while (std::getline(*currentInputStream, subLigne) && subLigne != "END_GROUPE") { // End of group indicated by "END_GROUPE"
                    Forme* forme = formeParserCOR::parse(subLigne); // Use the chain of parsers.
                    if (forme) {
                        groupe->addForme(std::shared_ptr<Forme>(forme));
                    }
                }

                return groupe;
            }
        }

        std::cout << "Ligne non reconnue par GroupeParser." << std::endl;
        return formeParserCOR::parse(ligne);
    }
};

#endif // GROUPEPARSER_H
