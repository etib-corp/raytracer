/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Lambertian
*/

#pragma once

#include "raytracer.hpp"
#include "AMaterial.hpp"
#include "Color.hpp"
#include "Texture/SolidColor.hpp"

/**
 * @brief The Lambertian class represents a Lambertian material in a ray tracer.
 *
 * Lambertian materials are diffuse materials that scatter light in all directions.
 * They have a constant albedo, which determines the color of the material.
 */
class Lambertian : public AMaterial {
    public:
        /**
         * @brief Constructs a Lambertian material with the given albedo.
         *
         * @param albedo The color of the material.
         */
        Lambertian(const Color& albedo);

        /**
         * @brief Constructs a Lambertian material with the given texture.
         *
         * @param texture The texture of the material.
         */
        Lambertian(std::shared_ptr<ITexture> texture);

        /**
         * @brief Destroys the Lambertian material.
         */
        ~Lambertian();

        /**
         * @brief Calculates the scattered ray after a ray hits the material.
         *
         * @param ray The incident ray.
         * @param hit The hit record containing information about the intersection.
         * @param attenuation The color attenuation of the scattered ray.
         * @param scattered The scattered ray.
         * @return true if the ray is scattered, false otherwise.
         */
        bool scatter(const Ray& ray, const HitRecord& hit, Color& attenuation, Ray& scattered) const override;

        std::shared_ptr<ITexture> getTexture() const { return this->_texture; }
        void setTexture(std::shared_ptr<ITexture> texture) { this->_texture = texture; }
    private:
        std::shared_ptr<ITexture> _texture; /**< The texture applied to the Material. */
};
