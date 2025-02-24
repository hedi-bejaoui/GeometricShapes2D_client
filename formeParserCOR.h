//
// Created by geffe on 24/02/2025.
//

#ifndef FORMEPARSERCOR_H
#define FORMEPARSERCOR_H

#include <string>
#include "Forme.h"


class formeParserCOR {
protected:
    formeParserCOR* nextParser; // Pointeur vers le prochain parser dans la chaîne
public:
    formeParserCOR() : nextParser(nullptr) {}

    void setNext(formeParserCOR* next) {
        nextParser = next;
    }

    virtual Forme* parse(const string& ligne) {
        if (nextParser) return nextParser->parse(ligne); // Passe au suivant si non reconnu
        return nullptr; // Aucun parser n'a reconnu la ligne
    }

    virtual ~formeParserCOR() = default;
};



#endif //FORMEPARSERCOR_H
