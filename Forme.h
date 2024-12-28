#ifndef FORME_H
#define FORME_H

#include <string>
#include <Transformation.h>
#include <Vecteur2D.h>
using namespace std;

class Groupe; // Forward declaration of Groupe

class Transformation; // Forward declaration of Transformation

/** Abstract base class representing a geometric shape */
class Forme {
protected:
    string color;
    const Groupe* parentGroup; // Pointer to the owning group (if any)

public:
    explicit Forme(const string& color = "black");
    virtual ~Forme();

    virtual void draw() const = 0;
    virtual double calculateArea() const = 0;
    virtual string toString() const = 0;

    const string& getColor() const;
    void setParentGroup(const Groupe* group);
    bool hasParentGroup() const;

    // Pure virtual methods for transformations
    virtual void translate(const Vecteur2D& translationVector) = 0;
    virtual void homothetie(const Vecteur2D& center, double scale) = 0;
    virtual void rotate(const Vecteur2D& center, double angle) = 0;

    virtual void accept(const Transformation& transformation) {
        transformation.apply(*this);
    }

    virtual void save(std::ostream& out) const = 0; // Polymorphic save method
};

#endif // FORME_H

