/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** AObject
*/

#pragma once

#include "raytracer.hpp"
#include "IObject.hpp"

/**
 * @class AObject
 * @brief A class representing an object with a position.
 *
 * This class provides methods to get and set the position of the object.
 */
class AObject : public IObject {
    public:
        /**
        * @brief Destructor for the AObject class.
        *
        * This function is a virtual destructor that allows for proper memory management when dealing with derived classes.
        */
        virtual ~AObject() = default;

        /**
        * @brief Get the current position of the object.
        *
        * This function returns the current position of the object as a Math::Vector<3> object.
        *
        * @return The current position of the object.
        */
        virtual Math::Vector<3> getPosition() const override;

        /**
        * @brief Set the position of the object.
        *
        * This function sets the position of the object to the provided Math::Vector<3> object.
        *
        * @param position The new position of the object.
        */
        virtual void setPosition(const Math::Vector<3> &position) override;

    protected:
        Math::Vector<3> _position; /**< The vector representing the position of the object. */
};
