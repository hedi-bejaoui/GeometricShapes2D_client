/**
 * @file Forme.h
 * @brief Declaration of the abstract base class Forme for geometric shapes.
 *
 * This file defines the abstract base class Forme, which serves as the interface for
 * all geometric shapes in the project. It provides methods for area calculation,
 * transformations, drawing, and saving, as well as handling group membership.
 */

#ifndef FORME_H
#define FORME_H

#include <string>
#include <Transformation.h>
#include <Vecteur2D.h>
#include "Visteur.h"

using namespace std;

class Groupe;          /**< Forward declaration of Groupe */
class Transformation;  /**< Forward declaration of Transformation */

/**
 * @class Forme
 * @brief Abstract base class for geometric shapes.
 *
 * The Forme class represents a geometric shape and defines the common interface
 * for all derived shape classes. It includes methods for computing the area,
 * converting the shape to a string, applying transformations (translation, homothety, rotation),
 * drawing the shape, and saving its data. A shape may also belong to a group.
 */
class Forme {
protected:
    string color;            /**< Color of the shape. Allowed values typically include "black", "blue", "red", "green", "yellow", and "cyan". */
    const Groupe* parentGroup; /**< Pointer to the owning group (if any). */

public:
    /**
     * @brief Constructs a Forme with the specified color.
     * @param color The color of the shape. Default is "black".
     */
    explicit Forme(const string& color = "black");

    /**
     * @brief Virtual destructor.
     *
     * Ensures proper cleanup of derived classes.
     */
    virtual ~Forme();

    /**
     * @brief Calculates the area of the shape.
     * @return The area as a double.
     *
     * Pure virtual function that must be implemented by derived classes.
     */
    virtual double calculateArea() const = 0;

    /**
     * @brief Converts the shape to its string representation.
     * @return A string that represents the shape.
     *
     * Pure virtual function that must be implemented by derived classes.
     */
    virtual string toString() const = 0;

    /**
     * @brief Retrieves the color of the shape.
     * @return A reference to the shape's color string.
     */
    const string& getColor() const;

    /**
     * @brief Sets the parent group for this shape.
     * @param group Pointer to the Groupe that this shape will belong to.
     */
    void setParentGroup(const Groupe* group);

    /**
     * @brief Checks if the shape belongs to a group.
     * @return True if the shape has a parent group; false otherwise.
     */
    bool hasParentGroup() const;

    // Pure virtual methods for transformations

    /**
     * @brief Translates the shape by the given vector.
     * @param translationVector The vector by which the shape is to be translated.
     */
    virtual void translate(const Vecteur2D& translationVector) = 0;

    /**
     * @brief Applies a homothety (scaling transformation) to the shape.
     * @param center The center of homothety.
     * @param scale The scaling factor.
     */
    virtual void homothetie(const Vecteur2D& center, double scale) = 0;

    /**
     * @brief Rotates the shape around a given center.
     * @param center The center of rotation.
     * @param angle The rotation angle in radians.
     */
    virtual void rotate(const Vecteur2D& center, double angle) = 0;


    /**
     * @brief Draws the shape using a visitor.
     * @param v Pointer to a Visiteur object that handles drawing.
     *
     * Pure virtual function that must be implemented by derived classes.
     */
    virtual void draw(const Visiteur *v) const = 0;

    /**
     * @brief Saves the shape using a visitor.
     * @param v Pointer to a Visiteur object that handles saving.
     *
     * Pure virtual function that must be implemented by derived classes.
     */
    virtual void save(const Visiteur *v) const = 0;
};

#endif // FORME_H
