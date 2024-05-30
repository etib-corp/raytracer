/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** AInput
*/

#ifndef AINPUT_HPP_
#define AINPUT_HPP_

#include "GUI/AInteractive.hpp"

namespace GUI {
    /**
     * @brief The AInput class is an abstract base class for input handling in the GUI module.
     *
     * This class serves as a base for all input-related classes in the GUI module. It provides a common interface for handling user input, such as mouse clicks, keyboard events, and other input sources.
     *
     * @author Nathan Maillot
     * @version 1.0
     * @date 2024
     */
    class AInput : public AInteractive {
    public:
        /**
         * @brief The AInput class's destructor is a virtual function that allows derived classes to override it.
         *
         * This ensures that when an object of a derived class is destroyed, the correct destructor for that class is called.
         *
         * @author Nathan Maillot
         * @version 1.0
         * @date 2024
         */
        virtual ~AInput() = default;
    };

}

#endif /* !AINPUT_HPP_ */
