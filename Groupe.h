/**
 * @file Groupe.h
 * @brief Declaration of the Groupe class representing a composite shape.
 *
 * This file defines the Groupe class, which is a composite geometric shape that contains a collection
 * of other shapes (Forme objects). The Groupe class implements the Forme interface and provides methods
 * for geometric transformations, area calculation, drawing, and saving using the Visitor design pattern.
 */

#ifndef GROUPE_H
#define GROUPE_H

#include "Forme.h"
#include <vector>
#include <memory>
#include "Visteur.h"

/**
 * @class Groupe
 * @brief Represents a group of geometric shapes.
 *
 * The Groupe class is a composite that holds multiple Forme objects. It allows performing geometric
 * transformations (translation, homothety, and rotation) on the entire group, calculates the total area
 * of the group by summing the areas of its elements, and supports drawing and saving operations using
 * the Visitor design pattern.
 */
class Groupe : public Forme {
    std::vector<std::shared_ptr<Forme>> formes; /**< Collection of shapes contained in the group. */

public:
    /**
     * @brief Constructs a Groupe object with an optional color.
     * @param color The color of the group. Default is "black".
     */
    Groupe(const std::string& color = "black");

    /**
     * @brief Retrieves the collection of shapes in the group.
     * @return A vector of shared pointers to Forme objects.
     */
    std::vector<std::shared_ptr<Forme>> getFormes() const;

    /**
     * @brief Adds a shape to the group.
     * @param forme A shared pointer to the Forme object to be added.
     */
    void addForme(const std::shared_ptr<Forme>& forme);

    /**
     * @brief Translates the group by applying the translation to each shape it contains.
     * @param translationVector The vector by which to translate the group.
     */
    void translate(const Vecteur2D& translationVector) override;

    /**
     * @brief Applies a homothety (scaling transformation) to the group.
     * @param center The center of the homothety.
     * @param scale The scaling factor.
     */
    void homothetie(const Vecteur2D& center, double scale) override;

    /**
     * @brief Rotates the group by applying the rotation to each shape it contains.
     * @param center The center of rotation.
     * @param angle The rotation angle in radians.
     */
    void rotate(const Vecteur2D& center, double angle) override;

    /**
     * @brief Calculates the total area of the group.
     * @return The sum of the areas of all shapes contained in the group.
     */
    double calculateArea() const override;

    /**
     * @brief Returns a string representation of the group.
     * @return A string describing the group and its contained shapes.
     */
    std::string toString() const override;

    /**
     * @brief Draws the group by drawing each shape within it.
     * @param v Pointer to a Visiteur object that handles the drawing.
     *
     * This method iterates over each shape in the group and calls its draw method.
     */
    void draw(const Visiteur *v) const override {
        for (const auto& forme : formes) {
            forme->draw(v);  // Draw each shape in the group
        }
    }

    /**
     * @brief Saves the group and its contained shapes using a visitor.
     * @param v Pointer to a Visiteur object that handles the saving.
     *
     * This method first saves the group itself and then iterates over each contained shape,
     * calling its save method.
     */
    void save(const Visiteur *v) const override {
        v->visit(*this); // Save the group itself if necessary
        for (const auto& forme : formes) {
            forme->save(v); // Save each shape in the group
        }
    }
};

#endif // GROUPE_H
