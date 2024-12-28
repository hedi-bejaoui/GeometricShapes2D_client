//
// Created by bejaoui on 12/28/2024.
//

#include "Translation.h"
#include "Forme.h"

void Translation::apply(Forme& forme) const {
    forme.translate(translationVector);
}

