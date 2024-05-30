/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** ATexture
*/

#pragma once

#include "ITexture.hpp"

/**
 * @brief The abstract base class for textures.
 *
 * This class defines the interface for textures used in the raytracer.
 * Subclasses of this class must implement the `value` function to provide
 * the color value of the texture at a given UV coordinate and point in 3D space.
 */
class ATexture : public ITexture {
    public:
        ~ATexture() = default;

        /**
         * @brief Get the color value of the texture at a given UV coordinate and point in 3D space.
         *
         * @param u The U coordinate of the texture.
         * @param v The V coordinate of the texture.
         * @param p The point in 3D space.
         * @return The color value of the texture at the given coordinates and point.
         */
        virtual Color value(double u, double v, const Math::Vector<3>& p) const = 0;

        virtual Type getType() const { return this->_type; };

    protected:
        Type _type;
};
