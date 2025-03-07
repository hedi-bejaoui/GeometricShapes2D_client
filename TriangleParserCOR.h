/**
 * @file TriangleParserCOR.h
 * @brief Declaration of the TriangleParserCOR class for parsing triangle representations.
 *
 * This file defines the TriangleParserCOR class, which derives from formeParserCOR.
 * It attempts to parse a string representation of a triangle by extracting its three vertices
 * and final color using a regular expression. If parsing is successful, a new Triangle object is created
 * and returned; otherwise, the parsing request is delegated to the next parser in the chain.
 */

#ifndef TRIANGLEPARSER_H
#define TRIANGLEPARSER_H

#include "formeParserCOR.h"
#include "Triangle.h"
#include <regex>
#include <iostream>

/**
 * @class TriangleParserCOR
 * @brief Parses a string into a Triangle object using the Chain of Responsibility pattern.
 *
 * The TriangleParserCOR class attempts to parse an input string representing a triangle.
 * It uses a regular expression to extract the coordinates of the three vertices and the final color.
 * If the string matches the expected format, a new Triangle object is constructed and returned.
 * Otherwise, the parsing is delegated to the next parser in the chain.
 */
class TriangleParserCOR : public formeParserCOR {
public:
    /**
     * @brief Attempts to parse a string representation of a triangle.
     * @param ligne The input string representing a triangle.
     * @return A pointer to a new Triangle object if parsing is successful; otherwise, the result from the next parser.
     *
     * This method uses a regular expression to match a triangle of the form:
     * "Triangle: (x1, y1, color: <color>), (x2, y2, color: <color>), (x3, y3, color: <color>), color: <finalColor>".
     * On a successful match, it extracts the coordinates of the three vertices and the final color,
     * then constructs and returns a new Triangle object.
     * Debug output is printed to the console to trace the parsing process.
     */
    Forme* parse(const std::string& ligne) override {
        std::cout << "Tentative de parsing : " << ligne << std::endl;

        // Regular expression to extract the vertices and final color.
        std::regex triangleRegex(R"(Triangle: \((\d+), (\d+), color: \w+\), \((\d+), (\d+), color: \w+\), \((\d+), (\d+), color: \w+\), color: (\w+))");
        std::smatch matches;

        if (std::regex_search(ligne, matches, triangleRegex)) {
            if (matches.size() == 8) { // 3 vertices + final color
                double x1 = std::stod(matches[1]);
                double y1 = std::stod(matches[2]);
                double x2 = std::stod(matches[3]);
                double y2 = std::stod(matches[4]);
                double x3 = std::stod(matches[5]);
                double y3 = std::stod(matches[6]);
                std::string color = matches[7]; // Final color of the triangle

                std::cout << "Triangle reconnu avec Sommets=("
                          << x1 << "," << y1 << "), ("
                          << x2 << "," << y2 << "), ("
                          << x3 << "," << y3 << "), Couleur=" << color << std::endl;

                return new Triangle(Vecteur2D(x1, y1), Vecteur2D(x2, y2), Vecteur2D(x3, y3), color);
            }
        }

        std::cout << "Ligne non reconnue par TriangleParser." << std::endl;
        return formeParserCOR::parse(ligne);
    }
};

#endif // TRIANGLEPARSER_H
