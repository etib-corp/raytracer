/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** LightBuilder
*/

#ifndef LIGHTBUILDER_HPP_
#define LIGHTBUILDER_HPP_

#include <bits/stdc++.h>
#include "Position.hpp"
#include "../Primitive/Sphere.hpp"
#include "Rotation.hpp"
#include "Translation.hpp"
#include "../Primitive/ObjectsList.hpp"
#include "../Primitive/Cylindre.hpp"
#include "../Primitive/Cone.hpp"
#include "../Primitive/Plan.hpp"
#include "../Parser/PMaterial.hpp"
#include "Light/Diffuse.hpp"
#include "Light/Directionnal.hpp"


/**
 * @class LightsBuilder
 * @brief A class for building primitives in a raytracer scene.
 *
 * The LightsBuilder class provides methods for adding spheres, planes, and cylinders to a scene.
 * It also provides a method for building the final list of objects in the scene.
 */
class LightBuilder {
    using i32 = int32_t;
    using d64 = double;
    public:
        /**
         * @brief Builds and returns the list of objects.
         *
         * This function builds and returns the list of objects that have been parsed and constructed.
         * The list is moved using std::move to avoid unnecessary copying.
         *
         * @return The list of objects.
         */
        LightBuilder& addLight(const Position& center, const Position& normal, const d64& radius, const PMaterial& material);
        /**
         * @brief Builds and returns the list of objects.
         *
         * This function builds and returns the list of objects that have been parsed and constructed.
         * The list is moved using std::move to avoid unnecessary copying.
         *
         * @return The list of objects.
         */
        [[nodiscard]] ObjectsList&& build(void)
        {
            return std::move(_objList);
        }
        /**
         * @brief Prints the object.
         *
         * This function prints the object to the standard output.
         */
        void print(void) const;

    private:
        /**
         * @brief A vector of Light objects.
         *
         * This vector stores a collection of Light objects used in the raytracer.
         * It provides a dynamic array-like functionality for managing the Lights.
         */
        std::vector<Disk> _lights;
        /**
         * @brief Represents a list of objects.
         *
         * The `ObjectsList` class is used to store a collection of objects.
         * It provides methods to add, remove, and access objects in the list.
         */
        ObjectsList _objList;
};

#endif /* !LIGHTBUILDER_HPP_ */
