/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Metal
*/

#pragma once

#include "raytracer.hpp"
#include "AMaterial.hpp"

/**
 * @class Metal
 * @brief Represents a metal material in the raytracer.
 *
 * The Metal class is a derived class of AMaterial and represents a metal material
 * that can be used in the raytracer. It provides a scatter function to calculate
 * the scattered ray and attenuation color when a ray hits a metal surface.
 */
class Metal : public AMaterial {
    public:
        /**
         * @brief Constructs a Metal material with the given albedo color and fuzziness.
         *
         * @param albedo The color of the metal material.
         * @param fuzz The fuzziness of the metal material (default is 0.0).
         */
        Metal(const Color &albedo, double fuzz = 0.0);

        /**
         * @brief Destroys the Metal material.
         */
        ~Metal();

        /**
         * @brief Calculates the scattered ray and attenuation color when a ray hits a metal surface.
         *
         * @param ray The incident ray.
         * @param hit The hit record containing information about the intersection.
         * @param attenuation The attenuation color of the scattered ray.
         * @param scattered The scattered ray.
         * @return True if the ray is scattered, false otherwise.
         */
        bool scatter(const Ray &ray, const HitRecord &hit, Color &attenuation, Ray &scattered) const;

        double getFuzz() const { return this->_fuzz; };
        void setFuzz(double fuzz) { this->_fuzz = fuzz; };

    private:
        double _fuzz; /**< The fuzziness of the metal material. */
};
