/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** HitRecord
*/

#pragma once

#include "raytracer.hpp"
#include "Vector.hpp"
#include "IMaterial.hpp"

class IMaterial;


/**
 * @brief Represents a record of a ray-object intersection.
 */
class HitRecord {
    public:
        /**
         * @brief Sets the face normal of the hit record based on the given ray and outward normal.
         *
         * @param ray The ray that intersected with the object.
         * @param outwardNormal The outward normal of the object at the intersection point.
         */
        void setFaceNormal(const Ray &ray, const Math::Vector<3> &outwardNormal)
        {
            Math::Vector<3> direction = ray.getDirection();
            this->frontFace = direction.dot(outwardNormal) < 0.0;
            this->normal = this->frontFace ? outwardNormal : outwardNormal * -1.0;
        }

        double t; /**< The parameter value of the ray at the intersection point. */
        Math::Vector<3> point; /**< The position of the intersection point. */
        Math::Vector<3> normal; /**< The normal vector at the intersection point. */
        std::shared_ptr<IMaterial> material; /**< The material of the intersected object. */
        double u; /**< The u texture coordinate at the intersection point. */
        double v; /**< The v texture coordinate at the intersection point. */
        bool frontFace; /**< Indicates whether the ray hit the front face of the object. */
};