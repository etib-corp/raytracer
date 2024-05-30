/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Ray
*/

#pragma once

#include "raytracer.hpp"
#include "Vector.hpp"

/**
 * @brief Represents a ray in 3D space.
 */
class Ray {
    public:
        /**
         * @brief Default constructor.
         * Initializes the ray with a point and direction of zero vectors.
         */
        Ray();

        /**
         * @brief Constructor.
         * Initializes the ray with the given point and direction.
         * @param point The starting point of the ray.
         * @param direction The direction of the ray.
         */
        Ray(Math::Vector<3> point, Math::Vector<3> direction);

        /**
         * @brief Virtual destructor.
         */
        virtual ~Ray() = default;

        /**
         * @brief Get the starting point of the ray.
         * @return The starting point of the ray.
         */
        Math::Vector<3> getPoint() const;

        /**
         * @brief Get the direction of the ray.
         * @return The direction of the ray.
         */
        Math::Vector<3> getDirection() const;

        /**
         * @brief Set the starting point of the ray.
         *
         * @param point The new starting point of the ray.
        */
        void setPoint(Math::Vector<3> point);

        /**
         * @brief Set the direction of the ray.
         *
         * @param direction The new direction of the ray.
        */
        void setDirection(Math::Vector<3> direction);

        /**
         * @brief Get the point at a given distance along the ray.
         *
         * @param t The distance along the ray.
         * @return The point at the given distance along the ray.
        */
        Math::Vector<3> at(double t) const;

    protected:
        Math::Vector<3> _point; /**< The starting point of the ray. */
        Math::Vector<3> _direction; /**< The direction of the ray. */

    private:
};

