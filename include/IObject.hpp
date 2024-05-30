/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** IObject
*/
#pragma once

#include "raytracer.hpp"
#include "Vector.hpp"

/**
 * @class IObject
 * @brief Interface for objects with positioning capabilities.
 *
 * This class serves as an interface for objects that have a position in 3D space.
 * It provides methods to get and set the position of the object.
 */
class IObject {
    public:
        /**
        * @brief Virtual destructor.
        *
        * This virtual destructor ensures that derived classes can be properly destroyed.
        */
        virtual ~IObject() = default;

        /**
        * @brief Get the position of the object.
        *
        * This method returns the current position of the object as a Vector3 object.
        *
        * @return The position of the object as a Vector3 object.
        */
        virtual Math::Vector<3> getPosition() const = 0;

        /**
        * @brief Set the position of the object.
        *
        * This method sets the position of the object to the given Vector3 object.
        *
        * @param position The new position of the object as a Vector3 object.
        */
        virtual void setPosition(const Math::Vector<3> &position) = 0;
};
