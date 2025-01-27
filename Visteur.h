//
// Created by geffe on 27/01/2025.
//

#ifndef VISTEURDESSINERJAVA_H
#define VISTEURDESSINERJAVA_H

class Cercle;
class Polygone;
class Segment;
class Triangle;
class Groupe;

class Visiteur {
public:
    virtual void visit(const Cercle &c) const = 0 ;
    virtual void visit(const Polygone &p) const = 0;
    virtual void visit(const Segment &s) const = 0;
    virtual void visit(const Triangle &t) const = 0;
    virtual void visit(const Groupe &g) const = 0;
};



#endif //VISTEURDESSINERJAVA_H
