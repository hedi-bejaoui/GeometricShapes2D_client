/**
 * @file CercleParserCOR.h
 * @brief Declaration of the CercleParserCOR class for parsing circle representations.
 *
 * This file defines the CercleParserCOR class, which derives from formeParserCOR. It attempts to parse
 * a string into a Cercle object using a regular expression. If the string is not recognized as a circle,
 * the parsing request is passed to the next parser in the chain.
 */

#ifndef CERCLEPARSER_H
#define CERCLEPARSER_H

#include <iostream>
#include "formeParserCOR.h"
#include "Cercle.h"
#include <sstream>
#include <regex>

/**
 * @class CercleParserCOR
 * @brief Parses a string representation of a circle and returns a Cercle object.
 *
 * The CercleParserCOR class uses a regular expression to extract the circle data from a string.
 * If the string matches the expected format, a new Cercle object is created and returned.
 * Otherwise, the parsing is delegated to the next parser in the chain.
 */
class CercleParserCOR : public formeParserCOR {
public:
    /**
     * @brief Attempts to parse a string into a Cercle object.
     * @param ligne The input string representing a circle.
     * @return A pointer to a new Cercle object if parsing is successful; otherwise, the result of the next parser.
     *
     * The method uses a regular expression to match the expected format:
     * "Cercle: center (x, y, color: <color1>), radius <radius>, color: <color2>".
     * On success, it extracts the center coordinates, radius, and final color, and creates a Cercle object.
     * Debug output is sent to the console to trace the parsing process.
     */
    Forme* parse(const std::string& ligne) override {
        std::cout << "Tentative de parsing : " << ligne << std::endl;

        // Regular expression to extract the circle's data.
        std::regex cercleRegex(R"(Cercle: center \((\d+), (\d+), color: (\w+)\), radius (\d+), color: (\w+))");
        std::smatch matches;

        if (std::regex_search(ligne, matches, cercleRegex)) {
            if (matches.size() == 6) {
                double x = std::stod(matches[1]);
                double y = std::stod(matches[2]);
                std::string color1 = matches[3]; // First color (e.g., "black")
                double rayon = std::stod(matches[4]);
                std::string color2 = matches[5]; // Final color (e.g., "red")

                std::cout << "Cercle reconnu avec x=" << x << ", y=" << y
                          << ", r=" << rayon << ", couleur=" << color2 << std::endl;

                return new Cercle(Vecteur2D(x, y), rayon, color2);
            }
        }

        std::cout << "Ligne non reconnue par CercleParser." << std::endl;
        return formeParserCOR::parse(ligne);
    }
};

#endif // CERCLEPARSER_H
