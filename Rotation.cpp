//
// Created by bejaoui on 12/28/2024.
//

#include "Rotation.h"
#include "Forme.h"

void Rotation::apply(Forme& forme) const {
    forme.rotate(center, angle);
}
