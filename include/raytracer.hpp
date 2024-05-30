/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** raytracer
*/

#pragma once

// C++ includes

#include <array>
#include <cmath>
#include <map>
#include <exception>
#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <random>
#include <vector>

// Constants

const double pi = 3.1415926535897932385;                            // The value of pi.
const double infinity = std::numeric_limits<double>::infinity();    // The value of infinity.

// Utility Functions

/**
 * @brief Converts degrees to radians.
 *
 * This function takes an angle in degrees and converts it to radians.
 *
 * @param degrees The angle in degrees.
 * @return The angle in radians.
 */
inline double degrees_to_radians(double degrees)
{
    return degrees * pi / 180.0;
}

inline double rad2deg(double rad)
{
    return rad * 180.0 / pi;
}

/**
 * Generates a random double value between 0 and 1.
 *
 * @return The generated random double value.
 */
inline double random_double()
{
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

/**
 * Generates a random double value between the specified minimum and maximum values.
 *
 * @param min The minimum value of the range (inclusive).
 * @param max The maximum value of the range (exclusive).
 * @return A random double value between min and max.
 */
inline double random_double(double min, double max)
{
    return min + (max - min) * random_double();
}
