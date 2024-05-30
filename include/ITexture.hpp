/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** ITexture
*/

#pragma once

#include "raytracer.hpp"
#include "Color.hpp"
#include "Vector.hpp"

/**
 * @brief The ITexture class represents an interface for textures in a raytracer.
 *
 * This class provides a common interface for different types of textures that can be used in a raytracer.
 * It defines a pure virtual function `value` that returns the color of the texture at a given UV coordinate and point.
 */
class ITexture {
    public:
        /**
         * @brief Destructor for the ITexture class.
         */
        virtual ~ITexture() = default;

        enum Type {
            CHECKER,
            SOLIDCOLOR
        };

        /**
         * @brief Returns the color of the texture at the given UV coordinate and point.
         *
         * @param u The U coordinate of the texture.
         * @param v The V coordinate of the texture.
         * @param p The point at which the texture is being evaluated.
         * @return The color of the texture at the given UV coordinate and point.
         */
        virtual Color value(double u, double v, const Math::Vector<3>& p) const = 0;

        virtual Type getType() const = 0;
};
