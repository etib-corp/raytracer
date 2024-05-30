/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** DoubleInput
*/

#ifndef DOUBLEINPUT_HPP_
#define DOUBLEINPUT_HPP_

#include "GUI/AInput.hpp"

namespace GUI {
    /**
     * @class DoubleInput
     * @brief A class for a double input field in a graphical user interface.
     *
     * This class represents a double input field in a graphical user interface. It inherits from the AInput class.
     *
     * @author Nathan Maillot
     * @version 1.0
     * @date 2024
     */
    class DoubleInput : public AInput {
        public:
            /**
             * @brief Constructor for the DoubleInput class.
             *
             * Initializes a new instance of the DoubleInput class with the specified title.
             *
             * @param[in] title The title of the input field.
             */
            DoubleInput(const std::string &title);

            /**
             * @brief Destructor for the DoubleInput class.
             *
             * Destroys an instance of the DoubleInput class.
             */
            ~DoubleInput() {}

            /**
             * @brief Displays the double input field in the graphical user interface.
             *
             * This method displays the double input field in the graphical user interface.
             */
            void display();

            /**
             * @brief Gets the current value of the double input field.
             *
             * This method retrieves the current value of the double input field.
             *
             * @return The current value of the double input field.
             */
            double getValue() const;

            /**
             * @brief Sets the value of the double input field.
             *
             * This method sets the value of the double input field.
             *
             * @param[in] value The new value for the double input field.
             */
            void setValue(double value);

        protected:
            /**
             * @brief The current value of the double input field.
             */
            float _value;
    };
}

#endif /* !DOUBLEINPUT_HPP_ */
