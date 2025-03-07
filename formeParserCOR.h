/**
 * @file FormeParserCOR.h
 * @brief Declaration of the formeParserCOR class for parsing shapes using the Chain of Responsibility pattern.
 *
 * This file defines the formeParserCOR class which serves as a base class for implementing parsers
 * that process a string representation of a shape (Forme). If a parser cannot recognize a given input,
 * it delegates the parsing to the next parser in the chain.
 */

#ifndef FORMEPARSERCOR_H
#define FORMEPARSERCOR_H

#include <string>
#include "Forme.h"

/**
 * @class formeParserCOR
 * @brief Base class for shape parsers using the Chain of Responsibility pattern.
 *
 * The formeParserCOR class defines the interface for parsing a string into a Forme object.
 * It maintains a pointer to the next parser in the chain. If the current parser cannot handle
 * the input string, it passes the responsibility to the next parser.
 */
class formeParserCOR {
protected:
    formeParserCOR* nextParser; /**< Pointer to the next parser in the chain. */

public:
    /**
     * @brief Constructs a formeParserCOR object.
     *
     * Initializes the next parser pointer to nullptr.
     */
    formeParserCOR() : nextParser(nullptr) {}

    /**
     * @brief Sets the next parser in the chain.
     * @param next A pointer to the next formeParserCOR object.
     */
    void setNext(formeParserCOR* next) {
        nextParser = next;
    }

    /**
     * @brief Parses a string into a Forme object.
     * @param ligne The input string representing a shape.
     * @return A pointer to a Forme object if the input is recognized; otherwise, nullptr.
     *
     * This method attempts to parse the input string. If the current parser cannot recognize the input,
     * it passes the parsing request to the next parser in the chain. If no parser recognizes the input,
     * it returns nullptr.
     */
    virtual Forme* parse(const std::string& ligne) {
        if (nextParser) return nextParser->parse(ligne); // Pass to the next parser if not recognized
        return nullptr; // No parser recognized the line
    }

    /**
     * @brief Virtual destructor.
     *
     * Ensures proper cleanup of derived parser objects.
     */
    virtual ~formeParserCOR() = default;
};

#endif //FORMEPARSERCOR_H
