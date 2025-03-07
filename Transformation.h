/**
* @file Transformation.h
 * @brief Declaration of the Transformation abstract class for geometric transformations.
 *
 * This header file defines the abstract base class Transformation, which provides an interface
 * for applying a transformation to a geometric shape (Forme).
 */

#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

class Forme; /**< Forward declaration of the Forme class. */

/**
 * @class Transformation
 * @brief Abstract base class for geometric transformations.
 *
 * The Transformation class defines the interface for applying a transformation to a Forme object.
 * Derived classes should implement the apply method to perform specific transformations
 * such as translation, rotation, or homothety.
 */
class Transformation {
public:
    /**
     * @brief Virtual destructor.
     *
     * Ensures proper cleanup of derived transformation objects.
     */
    virtual ~Transformation() {}

    /**
     * @brief Applies the transformation to a given shape.
     * @param forme The shape (Forme) to which the transformation is applied.
     *
     * This pure virtual function must be implemented by all derived classes to define how
     * the transformation affects the provided shape.
     */
    virtual void apply(Forme& forme) const = 0;
};

#endif // TRANSFORMATION_H
