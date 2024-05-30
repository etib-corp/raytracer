/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Checker
*/

#pragma once

#include "ATexture.hpp"
#include "Texture/SolidColor.hpp"

/**
 * @class Checker
 * @brief Represents a checkerboard texture.
 *
 * The Checker class is a concrete implementation of the ATexture abstract class.
 * It represents a checkerboard texture that alternates between two given textures or colors.
 */
class Checker : public ATexture {
    public:
        /**
         * @brief Constructor for the Checker class.
         * @param scale The scale factor for the checkerboard pattern.
         * @param even The texture to be used for the even squares of the checkerboard.
         * @param odd The texture to be used for the odd squares of the checkerboard.
         */
        Checker(double scale, std::shared_ptr<ITexture> even, std::shared_ptr<ITexture> odd);

        /**
         * @brief Constructor for the Checker class.
         * @param scale The scale factor for the checkerboard pattern.
         * @param even The color to be used for the even squares of the checkerboard.
         * @param odd The color to be used for the odd squares of the checkerboard.
         */
        Checker(double scale, const Color& even, const Color& odd);

        /**
         * @brief Destructor for the Checker class.
         */
        ~Checker();

        /**
         * @brief Calculates the color value of the checkerboard texture at a given UV coordinate and point.
         * @param u The U coordinate of the texture.
         * @param v The V coordinate of the texture.
         * @param p The point in 3D space.
         * @return The color value of the checkerboard texture at the given coordinates and point.
         */
        Color value(double u, double v, const Math::Vector<3>& p) const override;

        std::shared_ptr<ITexture> getOdd() const { return this->_odd; }
        std::shared_ptr<ITexture> getEven() const { return this->_even; }

        void setOdd(std::shared_ptr<ITexture> texture) { this->_odd = texture; }
        void setEven(std::shared_ptr<ITexture> texture) { this->_even = texture; }

        double getScale() const { return this->_invScale; }
        void setScale(double scale) { this->_invScale = scale; }

    private:
        double _invScale; /**< The inverse scale factor for the checkerboard pattern. */
        std::shared_ptr<ITexture> _even; /**< The texture for the even squares of the checkerboard. */
        std::shared_ptr<ITexture> _odd; /**< The texture for the odd squares of the checkerboard. */
};
