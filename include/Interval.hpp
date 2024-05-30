/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Interval
*/

#pragma once

#include "raytracer.hpp"

/**
 * @file Interval.hpp
 * @brief Defines the Interval class.
 */

/**
 * @class Interval
 * @brief Represents a mathematical interval.
 *
 * The `Interval` class can be used to store a range of values.
 * It provides methods to manipulate and query the interval.
 */
class Interval {
    public:
        /**
         * @brief Default constructor.
         *
         * Constructs an empty interval with minimum and maximum values set to 0.
         */
        Interval();

        /**
         * @brief Constructor.
         *
         * Constructs an interval with the specified minimum and maximum values.
         *
         * @param min The minimum value of the interval.
         * @param max The maximum value of the interval.
         */
        Interval(double min, double max);

        /**
         * @brief Destructor.
         *
         * Destroys the interval object.
         */
        ~Interval();

        /**
         * @brief Get the minimum value of the interval.
         *
         * @return The minimum value of the interval.
         */
        double getMin() const;

        /**
         * @brief Get the maximum value of the interval.
         *
         * @return The maximum value of the interval.
         */
        double getMax() const;

        /**
         * @brief Set the minimum value of the interval.
         *
         * @param min The new minimum value of the interval.
         */
        void setMin(double min);

        /**
         * @brief Set the maximum value of the interval.
         *
         * @param max The new maximum value of the interval.
         */
        void setMax(double max);

        /**
         * @brief Get the size of the interval.
         *
         * @return The size of the interval (max - min).
         */
        double size() const;

        /**
         * @brief Check if the interval contains a value.
         *
         * @param value The value to check.
         * @return True if the value is within the interval, false otherwise.
         */
        bool contains(double value) const;

        /**
         * @brief Check if the interval surrounds a value.
         *
         * @param value The value to check.
         * @return True if the value is surrounded by the interval, false otherwise.
         */
        bool surrounds(double value) const;

        /**
         * @brief Clamp a value to the interval.
         *
         * If the value is outside the interval, it is clamped to the nearest boundary.
         *
         * @param value The value to clamp.
         * @return The clamped value.
         */
        double clamp(double value) const;

        /**
         * @brief Empty interval.
         *
         * An empty interval has minimum and maximum values set to 0.
         */
        static const Interval empty;

        /**
         * @brief Universe interval.
         *
         * A universe interval has minimum and maximum values set to positive and negative infinity.
         */
        static const Interval universe;

    private:
        double min; /**< The minimum value of the interval. */
        double max; /**< The maximum value of the interval. */
};