/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Directionnal
*/

#pragma once

#include "AMaterial.hpp"
#include "ITexture.hpp"
#include "Texture/SolidColor.hpp"

/**
 * @class Directionnal
 * @brief Represents a directional light source in a raytracer.
 *
 * The Directionnal class is a subclass of AMaterial and represents a directional light source
 * in a raytracer. It can be initialized with a texture or a color.
 */
class Directionnal : public AMaterial {
    public:
        /**
         * @brief Constructs a Directionnal object with the given texture.
         * @param texture The texture to be used for the directional light.
         */
        Directionnal(const std::shared_ptr<ITexture>& texture);

        /**
         * @brief Constructs a Directionnal object with the given color.
         * @param color The color of the directional light.
         */
        Directionnal(const Color& color);

        /**
         * @brief Destroys the Directionnal object.
         */
        ~Directionnal();

        /**
         * @brief Calculates the emitted color of the directional light at a given point.
         * @param ray The incident ray.
         * @param record The hit record of the ray intersection.
         * @param u The texture coordinate u.
         * @param v The texture coordinate v.
         * @param point The point at which the emitted color is calculated.
         * @return The emitted color of the directional light.
         */
        Color emitted(const Ray& ray, const HitRecord& record, double u, double v, const Math::Vector<3>& point) const override;

    private:
        std::shared_ptr<ITexture> _texture; /**< The texture of the directional light. */
};
