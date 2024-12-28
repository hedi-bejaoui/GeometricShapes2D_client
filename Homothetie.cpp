//
// Created by bejaoui on 12/28/2024.
//

#include "Homothetie.h"
#include "Forme.h"

void Homothetie::apply(Forme& forme) const {
    forme.homothetie(center, scale);
}
