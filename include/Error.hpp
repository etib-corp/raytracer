/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Error
*/

#pragma once

#include "raytracer.hpp"

/**
 * @class Error
 * @brief This class represents a custom exception that can be thrown when an error occurs.
 *
 * @details The Error class inherits from the standard exception class and provides a way to store and retrieve an error message.
 *
 * @tparam None
 */
class Error : public std::exception {
    public:
        /**
        * @brief Constructs an Error object with the specified error message.
        *
        * @param[in] message The error message to be associated with the exception.
        */
        Error(const std::string& message) : _message(message) {}

        /**
        * @brief Destroys the Error object.
        *
        * @details The default destructor is provided by the base class std::exception.
        */
        ~Error() = default;

        /**
        * @brief Retrieves the error message associated with the exception.
        *
        * @return A pointer to a null-terminated string containing the error message.
        */
        const char *what() const noexcept override { return _message.c_str(); }

    protected:
        std::string _message; /**< The error message associated with the exception. */
};