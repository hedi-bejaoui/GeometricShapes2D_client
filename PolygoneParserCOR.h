/**
 * @file PolygoneParserCOR.h
 * @brief Declaration of the PolygoneParserCOR class for parsing polygon representations.
 *
 * This file defines the PolygoneParserCOR class, which derives from formeParserCOR.
 * It attempts to parse a string representation of a polygon by extracting its vertices
 * and final color using a regular expression. If successful, it constructs and returns a new
 * Polygone object; otherwise, it delegates parsing to the next parser in the chain.
 */

#ifndef POLYGONEPARSERCOR_H
#define POLYGONEPARSERCOR_H

#include "formeParserCOR.h"
#include "Polygone.h"
#include <regex>
#include <iostream>
#include <sstream>

/**
 * @class PolygoneParserCOR
 * @brief Parses a string into a Polygone object using the Chain of Responsibility pattern.
 *
 * The PolygoneParserCOR class attempts to extract a list of vertices and a final color from an input string.
 * It uses a regular expression to match the expected format. If the string is recognized, a new Polygone
 * object is created with the extracted vertices and color. If not, the parsing request is delegated to
 * the next parser in the chain.
 */
class PolygoneParserCOR : public formeParserCOR {
public:
    /**
     * @brief Attempts to parse a string representation of a polygon into a Polygone object.
     * @param ligne The input string representing a polygon.
     * @return A pointer to a new Polygone object if parsing is successful; otherwise, the result from the next parser.
     *
     * This method uses a regular expression to extract the vertices and final color from the input string.
     * Each vertex is expected to match the pattern "(x, y, color: <color>)". The vertices are collected into a vector,
     * and then a new Polygone object is created and returned. Debug output is printed to the console to trace the parsing process.
     */
    Forme* parse(const std::string& ligne) override {
        std::cout << "Tentative de parsing : " << ligne << std::endl;

        // Regular expression to extract the vertices and final color.
        std::regex polygoneRegex(R"(Polygone: ((?:\(\d+, \d+, color: \w+\) )+), color: (\w+))");
        std::smatch matches;

        if (std::regex_search(ligne, matches, polygoneRegex)) {
            if (matches.size() == 3) { // One for the list of vertices and one for the color.
                std::string pointsStr = matches[1]; // List of vertices.
                std::string color = matches[2];       // Final color.

                std::vector<Vecteur2D> points;
                std::regex pointRegex(R"(\((\d+), (\d+), color: \w+\))");
                std::smatch pointMatches;
                std::string::const_iterator searchStart(pointsStr.cbegin());

                // Extraction of vertices.
                while (std::regex_search(searchStart, pointsStr.cend(), pointMatches, pointRegex)) {
                    double x = std::stod(pointMatches[1]);
                    double y = std::stod(pointMatches[2]);
                    points.emplace_back(x, y);
                    searchStart = pointMatches.suffix().first;
                }

                std::cout << "Polygone reconnu avec " << points.size() << " sommets, Couleur=" << color << std::endl;

                return new Polygone(points, color);
            }
        }

        std::cout << "Ligne non reconnue par PolygoneParser." << std::endl;
        return formeParserCOR::parse(ligne);
    }
};

#endif // POLYGONEPARSERCOR_H
