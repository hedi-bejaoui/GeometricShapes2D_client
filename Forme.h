#ifndef FORME_H
#define FORME_H

#include <string>
using namespace std;

class Groupe; // Forward declaration of Groupe

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
};

#endif // FORME_H

