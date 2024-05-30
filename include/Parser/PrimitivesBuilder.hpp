/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** PrimitivesBuilder
*/

#ifndef PRIMITIVESBUILDER_HPP_
#define PRIMITIVESBUILDER_HPP_

#include <bits/stdc++.h>
// #include "Plane.hpp"
#include "Position.hpp"
#include "../Primitive/Sphere.hpp"
#include "Rotation.hpp"
#include "Translation.hpp"
#include "../Primitive/ObjectsList.hpp"
#include "../Primitive/Cylindre.hpp"
#include "../Primitive/Cone.hpp"
#include "../Primitive/Plan.hpp"
#include "../Parser/PMaterial.hpp"


/**
 * @class PrimitivesBuilder
 * @brief A class for building primitives in a raytracer scene.
 *
 * The PrimitivesBuilder class provides methods for adding spheres, planes, and cylinders to a scene.
 * It also provides a method for building the final list of objects in the scene.
 */
class PrimitivesBuilder {
    using i32 = int32_t;
    using d64 = double;
    public:
        /**
         * @brief Adds a sphere primitive to the scene.
         *
         * This function creates a sphere with the specified position, radius, color, rotation, translation, and material,
         * and adds it to the scene being built by the `PrimitivesBuilder` object.
         *
         * @param position The position of the sphere in 3D space.
         * @param radius The radius of the sphere.
         * @param color The color of the sphere.
         * @param rotation The rotation of the sphere.
         * @param translation The translation of the sphere.
         * @param material The material of the sphere.
         * @return A reference to the `PrimitivesBuilder` object, allowing for method chaining.
         */
        PrimitivesBuilder& addSphere(const Position& position, d64 radius, const Color& color, const Rotation& rotation, const Translation& translation, const PMaterial& material);
        /**
         * @brief Adds a plane primitive to the builder.
         *
         * This function adds a plane primitive to the builder with the specified axis, position, and color.
         *
         * @param axis The axis along which the plane is positioned ('x', 'y', or 'z').
         * @param position The position of the plane along the specified axis.
         * @param color The color of the plane.
         * @return A reference to the `PrimitivesBuilder` object for method chaining.
         */
        PrimitivesBuilder& addPlane(std::string axis, d64 position, const Color& color);
        /**
         * @brief Adds a cylinder primitive to the builder.
         *
         * This function adds a cylinder primitive to the builder with the specified position, radius, depth, and material.
         *
         * @param position The position of the cylinder.
         * @param radius The radius of the cylinder.
         * @param depth The depth of the cylinder.
         * @param material The material of the cylinder.
         * @return A reference to the PrimitivesBuilder object.
         */
        PrimitivesBuilder& addCylindre(const Position& position, const d64& radius, const d64& depth, const PMaterial& material);
        /**
         * @brief Builds and returns the list of objects.
         *
         * This function builds and returns the list of objects that have been parsed and constructed.
         * The list is moved using std::move to avoid unnecessary copying.
         *
         * @return The list of objects.
         */
        PrimitivesBuilder& addCone(const Position& position, const d64& radius, const d64& depth, const PMaterial& material);
        /**
         * @brief Builds and returns the list of objects.
         *
         * This function builds and returns the list of objects that have been parsed and constructed.
         * The list is moved using std::move to avoid unnecessary copying.
         *
         * @return The list of objects.
         */
        PrimitivesBuilder& addDisk(const Position& center, const Position& normal, const d64& radius, const PMaterial& material);
        /**
         * @brief Builds and returns the list of objects.
         *
         * This function builds and returns the list of objects that have been parsed and constructed.
         * The list is moved using std::move to avoid unnecessary copying.
         *
         * @return The list of objects.
         */
        PrimitivesBuilder& addLight(const Position& center, const Position& normal, const d64& radius, const PMaterial& material);
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
         * @brief A vector of Sphere objects.
         *
         * This vector stores a collection of Sphere objects used in the raytracer.
         * It provides a dynamic array-like functionality for managing the spheres.
         */
        std::vector<Sphere> _spheres;
        /**
         * @brief A container that holds a collection of `Plane` objects.
         *
         * This container provides dynamic array functionality, allowing you to add, remove, and access `Plane` objects.
         */
        std::vector<Plan> _planes;
        /**
         * @brief A container that holds a collection of Cylindre objects.
         *
         * This vector is used to store instances of the Cylindre class.
         * It provides dynamic size adjustment and efficient element access.
         */
        std::vector<Cylindre> _cylindre;
        /**
         * @brief A container that holds a collection of Cylindre objects.
         *
         * This vector is used to store instances of the Cylindre class.
         * It provides dynamic size adjustment and efficient element access.
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

#endif /* !PRIMITIVESBUILDER_HPP_ */
