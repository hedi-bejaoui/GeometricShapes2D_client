/**
 * @file SegmentParserCOR.h
 * @brief Declaration of the SegmentParserCOR class for parsing segment representations.
 *
 * This file defines the SegmentParserCOR class, which derives from formeParserCOR. It attempts to
 * parse a string representation of a segment by extracting its endpoints and final color using a regular
 * expression. If the parsing is successful, a new Segment object is created and returned; otherwise,
 * the parsing request is delegated to the next parser in the chain.
 */

#ifndef SEGMENTPARSERCOR_H
#define SEGMENTPARSERCOR_H

#include "formeParserCOR.h"
#include "Segment.h"
#include <regex>
#include <iostream>

/**
 * @class SegmentParserCOR
 * @brief Parses a string into a Segment object using the Chain of Responsibility pattern.
 *
 * The SegmentParserCOR class attempts to parse an input string representing a segment. It uses a regular expression
 * to extract the endpoints and final color of the segment. If the string matches the expected format, a new Segment
 * object is created and returned. If not, the parsing is delegated to the next parser in the chain.
 */
class SegmentParserCOR : public formeParserCOR {
public:
    /**
     * @brief Attempts to parse a string representation of a segment.
     * @param ligne The input string representing a segment.
     * @return A pointer to a new Segment object if parsing is successful; otherwise, the result from the next parser.
     *
     * This method uses a regular expression to match a segment of the form:
     * "Segment: (x1, y1, color: <color>) to (x2, y2, color: <color>), color: <finalColor>".
     * On a successful match, it extracts the endpoint coordinates and the final color, then constructs and returns
     * a new Segment object. Debug information is printed to the console during the parsing process.
     */
    Forme* parse(const std::string& ligne) override {
        std::cout << "Tentative de parsing : " << ligne << std::endl;

        // Regular expression to extract the endpoints and final color.
        std::regex segmentRegex(R"(Segment: \((\d+), (\d+), color: \w+\) to \((\d+), (\d+), color: \w+\), color: (\w+))");
        std::smatch matches;

        if (std::regex_search(ligne, matches, segmentRegex)) {
            if (matches.size() == 6) { // Two endpoints + final color
                double x1 = std::stod(matches[1]);
                double y1 = std::stod(matches[2]);
                double x2 = std::stod(matches[3]);
                double y2 = std::stod(matches[4]);
                std::string color = matches[5]; // Final color of the segment

                std::cout << "Segment reconnu avec Points=("
                          << x1 << "," << y1 << ") to ("
                          << x2 << "," << y2 << "), Couleur=" << color << std::endl;

                return new Segment(Vecteur2D(x1, y1), Vecteur2D(x2, y2), color);
            }
        }

        std::cout << "Ligne non reconnue par SegmentParser." << std::endl;
        return formeParserCOR::parse(ligne);
    }
};

#endif // SEGMENTPARSERCOR_H
