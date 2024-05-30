/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Dielectric
*/

#pragma once

#include "raytracer.hpp"
#include "AMaterial.hpp"

/**
 * @brief Dielectric material class.
 *
 * This class represents a dielectric material in a ray tracer.
 * It inherits from the AMaterial base class.
 */
class Dielectric : public AMaterial {
    public:
        /**
         * @brief Constructor for Dielectric.
         * @param refractive_index The refractive index of the dielectric material.
         */
        Dielectric(double refractive_index);

        /**
         * @brief Destructor for Dielectric.
         */
        ~Dielectric();

        /**
         * @brief Scatter function for Dielectric.
         *
         * This function scatters a ray when it hits a dielectric material.
         * It calculates the scattered ray and the attenuation of the ray.
         *
         * @param ray_in The incident ray.
         * @param rec The hit record containing information about the intersection point.
         * @param attenuation The attenuation of the ray.
         * @param scattered The scattered ray.
         * @return True if the ray is scattered, false otherwise.
         */
        bool scatter(const Ray &ray_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const;

        void setRefractiveIndex(double refractive_index) { this->_refractive_index = refractive_index; }
        double getRefractiveIndex() const { return this->_refractive_index; }

    private:
        double _refractive_index; /**< The refractive index of the dielectric material. */
};
