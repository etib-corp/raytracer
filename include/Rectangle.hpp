/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Rectangle
*/

#pragma once

#include "raytracer.hpp"
#include "Vector.hpp"

namespace Math {
        /**
         * @file Rectangle.hpp
         * @brief Contains the declaration of the Rectangle class.
         */

        /**
         * @class Rectangle
         * @brief Represents a rectangle shape.
         *
         * The Rectangle class provides functionality to create and manipulate rectangle objects.
         * It includes methods to calculate the area, perimeter, and check if a point is inside the rectangle.
         */
        class Rectangle {
            public:
                /**
                 * @brief Default constructor for the Rectangle class.
                 *
                 * This constructor creates a Rectangle object with default `origin`, `topSide` and `leftSide` values.
                 */
                Rectangle();

                /**
                 * @brief Constructs a Rectangle object with the specified width and height.
                 *
                 * @param origin The origin point of the rectangle.
                 * @param topSide The top side of the rectangle.
                 * @param leftSide The left side of the rectangle.
                 */
                Rectangle(const Math::Vector<3> &origin, const Math::Vector<3> &topSide, const Math::Vector<3> &leftSide);

                /**
                 * @brief Destructor for the Rectangle class.
                 *
                 * This destructor is responsible for cleaning up any resources allocated by the Rectangle class.
                 * It is automatically called when an instance of the Rectangle class is destroyed.
                 */
                ~Rectangle();

                /**
                 * @brief Sets the origin point of the rectangle.
                 *
                 * @param origin The origin point of the rectangle.
                 */
                void setOrigin(const Vector<3> &origin);

                /**
                 * @brief Sets the top side vector of the rectangle.
                 *
                 * @param topSide The top side vector of the rectangle.
                 */
                void setTopSide(const Vector<3> &topSide);

                /**
                 * @brief Sets the left side vector of the rectangle.
                 *
                 * @param leftSide The left side vector of the rectangle.
                 */
                void setLeftSide(const Vector<3> &leftSide);

                /**
                 * @brief Returns the origin point of the rectangle.
                */
                Vector<3> getOrigin() const;

                /**
                 * @brief Returns the top side vector of the rectangle.
                */
                Vector<3> getTopSide() const;

                /**
                 * @brief Returns the left side vector of the rectangle.
                */
                Vector<3> getLeftSide() const;

                /**
                 * @brief Returns the point at the specified UV coordinates.
                 *
                 * @param u The U coordinate.
                 * @param v The V coordinate.
                 * @return The point at the specified UV coordinates.
                 */
                Vector<3> pointAt(double u, double v) const;

            protected:
            private:
                Vector<3> _origin; /**< The origin point of the rectangle. */
                Vector<3> _topSide; /**< The top side of the rectangle. */
                Vector<3> _leftSide; /**< The left side of the rectangle. */
        };
}
