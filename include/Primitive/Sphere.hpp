/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Sphere
*/

#pragma once

#include "raytracer.hpp"

#include "Vector.hpp"
#include "Ray.hpp"
#include "APrimitive.hpp"


/**
 * @class Sphere
 * @brief Represents a sphere primitive in a ray tracer.
 *
 * The Sphere class inherits from the APrimitive class and provides
 * functionality to represent a sphere in a ray tracer scene. It stores
 * the center and radius of the sphere and implements the hit() function
 * to check for ray-sphere intersection.
 */
class Sphere : public APrimitive {
    public:
        /**
         * @brief Default constructor.
         */
        Sphere();
        Sphere(const Sphere&) = default;

        Sphere(Sphere&&) = default;

        /**
         * @brief Parameterized constructor.
         * @param center The center of the sphere.
         * @param radius The radius of the sphere.
         */
        Sphere(const Math::Vector<3>& center, double radius, std::shared_ptr<IMaterial> material);

        /**
         * @brief Default destructor.
         */
        ~Sphere() = default;

        void setCenter(const Math::Vector<3>& center) noexcept
        {
            _center = center;
        }

        void setRadius(double radius) noexcept
        {
            _radius = radius;
        }

        [[nodiscard]] double getRadius(void) const noexcept
        {
            return _radius;
        }

        void setMaterial(std::shared_ptr<IMaterial> material) noexcept
        {
            _material = material;
        }

        [[nodiscard]] std::shared_ptr<IMaterial> getMaterial(void) const noexcept
        {
            return _material;
        }

        /**
         * @brief Checks for ray-sphere intersection.
         * @param ray The ray to check intersection with.
         * @param ray_t The interval of the ray to consider.
         * @param record The hit record to update if intersection occurs.
         * @return True if intersection occurs, false otherwise.
         */
        bool hit(const Ray &ray, const Interval& ray_t, HitRecord& record) const override;

        static inline void getSphereUV(const Math::Vector<3>& p, double& u, double& v)
        {
            double phi = atan2(-p[2], p[0]) + M_PI;
            double theta = acos(-p[1]);

            u = phi / (2 * M_PI);
            v = theta / M_PI;
        }

        /**
         * @brief Gets the center of the sphere.
         * @return The center of the sphere.
         */
        Math::Vector<3> getCenter() const;

        // void setRadius(double radius)
        // {
        //     this->_radius = radius;
        // }

        // double getRadius()
        // {
        //     return this->_radius;
        // }

    private:
        Math::Vector<3> _center; /**< The center of the sphere. */
        double _radius; /**< The radius of the sphere. */
};
