/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Plane
*/

#ifndef PLANE_HPP_
#define PLANE_HPP_

#include <bits/stdc++.h>
#include "Color.hpp"

/**
 * @brief The Plane class represents a plane in a 3D space.
 */
class Plane {
public:
    /**
     * @brief Sets the axis of the plane.
     *
     * @param axis The axis of the plane ('x', 'y', or 'z').
     */
    void setAxis(char axis)
    {
        _axis = axis;
    }

    /**
     * @brief Sets the position of the plane.
     *
     * @param position The position of the plane.
     */
    void setPosition(float position)
    {
        _position = position;
    }

    /**
     * @brief Sets the color of the plane.
     *
     * @param color The color of the plane.
     */
    void setColor(const Color& color)
    {
        _color = color;
    }

    /**
     * @brief Prints the details of the plane.
     */
    void print(void) const
    {
        // std::cout << "  Plane:\n"
        //           << "    Axis: " << _axis << "\n"
        //           << "    Position: " << _position << "\n"
        //           << "    Color: (" << _color.r << ", " << _color.g << ", " << _color.b << ")\n";
    }

private:
    char _axis;     ///< The axis of the plane ('x', 'y', or 'z').
    float _position;    ///< The position of the plane.
    Color _color;   ///< The color of the plane.
};

#endif /* !PLANE_HPP_ */
