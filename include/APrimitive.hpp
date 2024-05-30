/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** APrimitive
*/
#pragma once

#include "raytracer.hpp"
#include "Ray.hpp"
#include "AObject.hpp"
#include "Interval.hpp"
#include "IMaterial.hpp"
#include "HitRecord.hpp"

/**
 * @class APrimitive
 * @brief Base class for all primitives in the scene.
 *
 * This class provides a basic interface for all primitives in the scene.
 * It includes a method to check if a ray intersects the primitive and a pointer to the material of the primitive.
 */
class APrimitive : public AObject {
    public:
        enum Type {
            SPHERE,
            PLANE,
            CYLINDER,
            CONE,
            DISK,
            NONE
        };
        /**
        * @brief Destructor for APrimitive.
        */
        virtual ~APrimitive() = default;

        APrimitive() = default;

        // APrimitive(const APrimitive&) = default;

        // APrimitive(APrimitive&&) = default;

        /**
        * @brief Checks if a ray intersects the primitive.
        *
        * @param[in] ray The ray to check for intersection.
        * @return True if the ray intersects the primitive, false otherwise.
        */
        virtual bool hit(const Ray &ray, const Interval& ray_t, HitRecord& record) const = 0;
        Type getType() const { return this->_type; }

        void setMaterial(std::shared_ptr<IMaterial> material) { this->_material = material; }
        std::shared_ptr<IMaterial> getMaterial() const { return this->_material; }

    protected:
        std::shared_ptr<IMaterial> _material; /**< Pointer to the material of the primitive. */
        Type _type = NONE; /**< Type of the primitive. */
};
