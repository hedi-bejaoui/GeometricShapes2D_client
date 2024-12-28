//
// Created by bejaoui on 12/28/2024.
//

#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

class Forme; // Forward declaration of Forme

/** Abstract base class for geometric transformations */
class Transformation {
public:
    virtual ~Transformation() {}
    virtual void apply(Forme& forme) const = 0;
};

#endif // TRANSFORMATION_H
