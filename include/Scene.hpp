/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Scene
*/
#pragma once

#include "raytracer.hpp"
#include "IObject.hpp"

/**
 * @class Scene
 * @brief The Scene class represents a scene in a game or simulation.
 *
 * It contains a collection of IObject pointers, which represent the objects in the scene.
 */
class Scene {
    public:
        /**
        * @brief Constructor for the Scene class.
        */
        Scene();

        /**
        * @brief Destructor for the Scene class.
        */
        ~Scene();

    protected:
        std::vector<std::unique_ptr<IObject>> _objects; /**< A vector of unique_ptr to IObject, which represents the objects in the scene. */
};
