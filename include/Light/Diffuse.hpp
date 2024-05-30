/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Diffuse
*/

#pragma once

#include "AMaterial.hpp"
#include "ITexture.hpp"
#include "Texture/SolidColor.hpp"

/**
 * @class Diffuse
 * @brief The Diffuse class represents a material with diffuse properties.
 *
 * @details The Diffuse class is a subclass of AMaterial and represents a diffuse material.
 * A diffuse material is a material that scatters light in all directions.
 *
 * This class inherits from the AMaterial class and provides an implementation
 * for the emitted() function, which calculates the emitted color of the material
 * based on the given ray, hit record, texture coordinates, and point in 3D space.
 */
class Diffuse : public AMaterial {
    public:
        /**
         * @brief Constructs a Diffuse material with the given texture.
         *
         * @param texture The texture to be used for the material.
         */
        Diffuse(const std::shared_ptr<ITexture>& texture);

        /**
         * @brief Constructs a Diffuse material with the given color.
         *
         * @param color The color to be used for the material.
         */
        Diffuse(const Color& color);

        /**
         * @brief Destroys the Diffuse material.
         */
        ~Diffuse();

        /**
         * @brief Calculates the emitted color of the material.
         *
         * This function calculates the emitted color of the material based on the
         * given ray, hit record, texture coordinates, and point in 3D space.
         *
         * @param ray The ray that hit the material.
         * @param record The hit record containing information about the intersection.
         * @param u The texture coordinate along the U axis.
         * @param v The texture coordinate along the V axis.
         * @param point The point in 3D space where the ray hit the material.
         * @return The emitted color of the material.
         */
        Color emitted(const Ray& ray, const HitRecord& record, double u, double v, const Math::Vector<3>& point) const override;

    private:
        std::shared_ptr<ITexture> _texture; /**< The texture used for the material. */
};
