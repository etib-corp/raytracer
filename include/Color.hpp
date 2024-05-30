/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Color
*/

#pragma once

#include "raytracer.hpp"
#include "Interval.hpp"

/**
 * @class Color
 * @brief The Color class represents a color with red, green, blue, and alpha components.
 *
 * The Color class has a constructor that takes red, green, and blue values as parameters,
 * along with an optional alpha value. If the alpha value is not provided, it defaults to 255.
 *
 * The class also has a copy constructor that creates a new Color object from an existing one.
 *
 * The Color class has private data members for the red, green, blue, and alpha components.
 */
class Color {
    public:
        /**
        * @brief Constructs a new Color object with the specified red, green, and blue values,
        * along with an optional alpha value. If the alpha value is not provided, it defaults to 1.0.
        *
        * @param r The red component of the color.
        * @param g The green component of the color.
        * @param b The blue component of the color.
        * @param a The alpha component of the color. Defaults to 1.0 if not provided.
        */
        Color(double r, double g, double b, double a = 1.0);

        /**
        * @brief Constructs a new Color object from an existing one.
        *
        * @param color The existing Color object to be copied.
        */
        Color(const Color& color);

        /**
        * @brief Default constructor that initializes the color with red, green, and blue components set to 0,
        * and the alpha component set to 1.0.
        */
        Color() : red(0), green(0), blue(0), alpha(1.0) {};

        /**
        * @brief Destructor for the Color class.
        */
        ~Color();

        void write(std::ostream &out);

        static double linearToGamma(double linear);

        /**
         * @brief Overloaded assignment operator that assigns the values of one Color object to another.
         *
         * @param scalar The double value to multiply the color by.
        */
        Color operator*(double scalar) const;

        Color operator*(const Color& color) const;

        /**
         * @brief Overloaded addition operator that adds the values of one Color object to another.
         *
         * @param color The Color object to add to the current one.
        */
        Color operator+(const Color& color) const;

        double red; /**< The red component of the color. */

        double green; /**< The green component of the color. */

        double blue; /**< The blue component of the color. */

        double alpha; /**< The alpha component of the color. */

    private:
};
