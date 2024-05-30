/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** SolidColor
*/

#pragma once

#include "ATexture.hpp"

/**
 * @brief The SolidColor class represents a solid color texture.
 *
 * This class inherits from the ATexture base class and provides a solid color value for a given UV coordinate and point.
 */
class SolidColor : public ATexture {
    public:
        /**
         * @brief Constructs a SolidColor object with the specified albedo color.
         *
         * @param albedo The albedo color of the solid color texture.
         */
        SolidColor(const Color& albedo);

        /**
         * @brief Constructs a SolidColor object with the specified RGB values.
         *
         * @param r The red component of the albedo color.
         * @param g The green component of the albedo color.
         * @param b The blue component of the albedo color.
         */
        SolidColor(double r, double g, double b);

        /**
         * @brief Destroys the SolidColor object.
         */
        ~SolidColor();

        /**
         * @brief Returns the color value of the solid color texture for the given UV coordinate and point.
         *
         * @param u The U coordinate.
         * @param v The V coordinate.
         * @param p The point in 3D space.
         * @return The color value of the solid color texture.
         */
        Color value(double u, double v, const Math::Vector<3>& p) const override;

        void setAlbedo(Color albedo) { this->_albedo = albedo; }
        Color getAlbedo() { return this->_albedo; }

    private:
        Color _albedo; /**< The albedo color of the solid color texture. */
};
