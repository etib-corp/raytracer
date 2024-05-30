/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** LightsBuilder
*/

#ifndef LIGHTSBUILDER_HPP_
#define LIGHTSBUILDER_HPP_

#include <bits/stdc++.h>
#include "Lights.hpp"

/**
 * @class LightsBuilder
 * @brief Builder class for creating Lights objects.
 *
 * The LightsBuilder class provides a convenient way to construct Lights objects
 * with different properties and configurations. It follows the Builder design pattern
 * and allows the user to set ambient and diffuse values, add point lights, and set
 * the type of light (directional or not). The build() method is used to obtain the
 * final Lights object.
 */
class LightsBuilder : public Lights {
    public:
        /**
         * @brief Set the ambient value for the Lights object.
         * @param ambient The ambient value to set.
         * @return A reference to the LightsBuilder object.
         */
        LightsBuilder& ambientSet(const float ambient)
        {
            _lights.ambientSet(ambient);
            return *this;
        }

        /**
         * @brief Set the diffuse value for the Lights object.
         * @param diffuse The diffuse value to set.
         * @return A reference to the LightsBuilder object.
         */
        LightsBuilder& diffuseSet(const float diffuse)
        {
            _lights.diffuseSet(diffuse);
            return *this;
        }

        /**
         * @brief Add a point light to the Lights object.
         * @param point The Point object representing the position of the point light.
         * @return A reference to the LightsBuilder object.
         */
        LightsBuilder& addPoint(const Point& point)
        {
            _points.push_back(point);
            return *this;
        }

        /**
         * @brief Set the Lights object as a directional light.
         * @return A reference to the LightsBuilder object.
         */
        LightsBuilder& directionalSet(void)
        {
            _lights.directionalSet();
            return *this;
        }

        /**
         * @brief Build and return the final Lights object.
         * @return The constructed Lights object.
         */
        Lights build()
        {
            _lights.pointsSet(_points);
            return _lights;
        }

    private:
        Lights _lights; /**< The Lights object being constructed. */
        std::vector<Point> _points; /**< The list of point lights to be added to the Lights object. */

    protected:
    private:
};

#endif /* !LIGHTSBUILDER_HPP_ */
