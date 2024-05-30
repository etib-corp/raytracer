/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** ObjectsList
*/

#pragma once

#include "raytracer.hpp"
#include "APrimitive.hpp"
#include "Interval.hpp"
#include "Primitive/Sphere.hpp"
#include "Primitive/Cylindre.hpp"
#include "Primitive/Cone.hpp"

/**
 * @brief The ObjectsList class represents a list of objects in a scene.
 *
 * This class inherits from the APrimitive class and provides functionality to store and manage a collection of objects.
 * It allows adding objects to the list, clearing the list, and checking for intersection with a ray.
 */
class ObjectsList : public APrimitive {
    public:
        /**
         * @brief Default constructor for ObjectsList.
         */
        ObjectsList();

        ObjectsList(ObjectsList&&) = default;

        /**
         * @brief Constructor for ObjectsList that initializes the list with a single object.
         * @param object The object to add to the list.
         */
        ObjectsList(std::shared_ptr<APrimitive> object);

        /**
         * @brief Destructor for ObjectsList.
         */
        ~ObjectsList();

        /**
         * @brief Checks if the given ray intersects with any object in the list.
         * @param ray The ray to check for intersection.
         * @param ray_t The interval of valid ray parameter values.
         * @param record The hit record to store the intersection information.
         * @return True if the ray intersects with an object, false otherwise.
         */
        bool hit(const Ray &ray, const Interval& ray_t, HitRecord &record) const override;

        /**
         * @brief Adds an object to the list.
         * @param object The object to add.
         */
        void add(const std::shared_ptr<APrimitive> &object);

        /**
         * @brief Clears the list of objects.
         */
        void clear();

        void print(void)
        {
            std::cout << "ObjectsList:" << std::endl;
            for (const auto& object_: _objects) {
                if (const auto& sphere = dynamic_cast<Sphere*>(object_.get())) {
                    std::cout << "Sphere:" << std::endl;
                    std::cout << "\tPosition=" << sphere->getPosition() << std::endl;
                    std::cout << "\tCenter=" << sphere->getCenter() << std::endl;
                    std::cout << "\tRadius=" << sphere->getRadius() << std::endl;
                    std::cout << "\tMaterial=" << sphere->getMaterial().get()->typeGet() << std::endl;
                    std::cout << "\tisColor=" << sphere->getMaterial().get()->hasColorGet() << std::endl;
                    std::cout << "\tisTexture=" << sphere->getMaterial().get()->hasTextureGet() << std::endl;
                    std::cout << "\tis=" << sphere->getMaterial().get()->hasTextureGet() << std::endl;
                }
                if (const auto& cylindre = dynamic_cast<Cylindre*>(object_.get())) {
                    std::cout << "Cylindre:" << std::endl;
                    std::cout << "\tPosition=" << cylindre->getPosition() << std::endl;
                    std::cout << "\tDepth=" << cylindre->getDepth() << std::endl;
                    std::cout << "\tRadius=" << cylindre->getRadius() << std::endl;
                    std::cout << "\tMaterial=" << cylindre->getMaterial().get()->typeGet() << std::endl;
                    std::cout << "\tisColor=" << cylindre->getMaterial().get()->hasColorGet() << std::endl;
                    std::cout << "\tisTexture=" << cylindre->getMaterial().get()->hasTextureGet() << std::endl;
                }
                if (const auto& cone = dynamic_cast<Cone*>(object_.get())) {
                    std::cout << "Cone:" << std::endl;
                    std::cout << "\tPosition=" << cone->getPosition() << std::endl;
                    std::cout << "\tDepth=" << cone->getHeight() << std::endl;
                    std::cout << "\tRadius=" << cone->getRadius() << std::endl;
                    std::cout << "\tMaterial=" << cone->getMaterial().get()->typeGet() << std::endl;
                    std::cout << "\tisColor=" << cone->getMaterial().get()->hasColorGet() << std::endl;
                    std::cout << "\tisTexture=" << cone->getMaterial().get()->hasTextureGet() << std::endl;
                }
            }
        }
        ObjectsList &operator=(ObjectsList &&) = default;
        std::vector<std::shared_ptr<APrimitive>> _objects; /**< The list of objects. */
    private:
};
