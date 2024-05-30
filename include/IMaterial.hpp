/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** IMaterial
*/
#pragma once

#include "raytracer.hpp"
#include "Ray.hpp"
#include "HitRecord.hpp"
#include "Color.hpp"

/**
 * @brief The IMaterial class represents an interface for materials used in ray tracing.
 *
 * This class provides a common interface for different types of materials that can be used
 * in ray tracing. It defines a pure virtual function scatter() that calculates the scattered
 * ray and attenuation color based on the incoming ray and hit record.
 */
class IMaterial {
    public:
        enum Type {
            DIELECTRIC,
            LAMBERTIAN,
            METAL,
            NONE
        };

        /**
         * @brief Virtual destructor for IMaterial.
         */
        virtual ~IMaterial() = default;

        /**
         * @brief Emit light from the material.
         * @param ray The incident ray.
         * @param record The hit record containing information about the intersection.
         * @param u The u texture coordinate.
         * @param v The v texture coordinate.
         * @param point The point of intersection.
         * @return The emitted color.
        */
        virtual Color emitted(const Ray& ray, const HitRecord& record, double u, double v, const Math::Vector<3>& point) const = 0;
        /**
         * @brief Calculates the scattered ray and attenuation color for a given incoming ray and hit record.
         *
         * This pure virtual function is implemented by derived classes to calculate the scattered ray
         * and attenuation color based on the incoming ray and hit record. The function returns true if
         * scattering occurs, and false otherwise.
         *
         * @param ray The incoming ray.
         * @param hit The hit record containing information about the intersection point.
         * @param attenuation The attenuation color.
         * @param scattered The scattered ray.
         * @return True if scattering occurs, false otherwise.
         */
        virtual bool scatter(const Ray& ray, const HitRecord& hit, Color& attenuation, Ray& scattered) const = 0;

        virtual std::string typeGet(void) = 0;
        virtual void typeSet(std::string) = 0;
        virtual void hasTextureSet(void) = 0;
        virtual void hasColorSet(void) = 0;
        virtual bool hasTextureGet(void) = 0;
        virtual bool hasColorGet(void) = 0;

        virtual Type getType() const = 0;
        virtual Color getAlbedo() const = 0;
        virtual void setAlbedo(const Color& albedo) = 0;
};
