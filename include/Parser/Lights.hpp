/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Lights
*/

#ifndef LIGHTS_HPP_
#define LIGHTS_HPP_

#include <bits/stdc++.h>

/**
 * @class Lights
 * @brief Represents a collection of lights in a scene.
 */
class Lights {
public:
    /**
     * @brief Set the ambient light intensity.
     * @param ambient The ambient light intensity.
     */
    void ambientSet(const float ambient)
    {
        _ambient = ambient;
    }

    /**
     * @brief Set the diffuse light intensity.
     * @param diffuse The diffuse light intensity.
     */
    void diffuseSet(const float diffuse)
    {
        _diffuse = diffuse;
    }

    /**
     * @brief Add a point light to the collection.
     * @param point The point light to add.
     */
    void addPoint(const Point& point)
    {
        _points.push_back(point);
    }

    /**
     * @brief Set the directional light.
     */
    void directionalSet(void)
    {
        // TODO: Implement this function
    }

    /**
     * @brief Set the list of point lights.
     * @param points The list of point lights.
     */
    void pointsSet(std::vector<Point> points)
    {
        _points = points;
    }

    /**
     * @brief Print the lights information.
     */
    void print() const {
        std::cout << "Lights:\n"
                  << "  Ambient: " << _ambient << "\n"
                  << "  Diffuse: " << _diffuse << "\n"
                  << "  Directional: " << "TODO:DEFINE LIST OF DIRECTIONNAL" << " degrees\n";
        std::cout << "  List of Point:" << "\n";
        for (const auto& point : _points) {
            std::cout << "      Point(" << point.x << ", " << point.y << ", " << point.z << ")\n";
        }
    }

private:
    Point _point;                   ///< The position of the light source.
    std::vector<Point> _points;     ///< The list of point lights.
    float _ambient;                 ///< The ambient light intensity.
    float _diffuse;                 ///< The diffuse light intensity.
};

#endif /* !LIGHTS_HPP_ */
