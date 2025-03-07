/**
* @file VisteurDESSINERJAVA.h
 * @brief Declaration of the Visiteur interface for visiting geometric shapes.
 *
 * This file defines the abstract class Visiteur which provides the interface for the Visitor
 * design pattern. It declares pure virtual functions for visiting various geometric shapes,
 * allowing concrete implementations to perform operations such as drawing or saving.
 */

#ifndef VISTEURDESSINERJAVA_H
#define VISTEURDESSINERJAVA_H

class Cercle;
class Polygone;
class Segment;
class Triangle;
class Groupe;

/**
 * @class Visiteur
 * @brief Abstract visitor interface for shape operations.
 *
 * The Visiteur class declares pure virtual functions for visiting different geometric shapes.
 * Concrete implementations of this interface should define the behavior for each shape type.
 */
class Visiteur {
public:
    /**
     * @brief Visits a Cercle object.
     * @param c The Cercle to be visited.
     */
    virtual void visit(const Cercle &c) const = 0;

    /**
     * @brief Visits a Polygone object.
     * @param p The Polygone to be visited.
     */
    virtual void visit(const Polygone &p) const = 0;

    /**
     * @brief Visits a Segment object.
     * @param s The Segment to be visited.
     */
    virtual void visit(const Segment &s) const = 0;

    /**
     * @brief Visits a Triangle object.
     * @param t The Triangle to be visited.
     */
    virtual void visit(const Triangle &t) const = 0;

    /**
     * @brief Visits a Groupe object.
     * @param g The Groupe to be visited.
     */
    virtual void visit(const Groupe &g) const = 0;
};

#endif // VISTEURDESSINERJAVA_H
