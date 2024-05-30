/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "GUI/AInteractive.hpp"

namespace GUI {
    /**
     * @brief The Button class is a subclass of AInteractive and represents a graphical button in the GUI.
     *
     * @details The Button class has a constructor that takes a title and a function pointer as parameters.
     * The function pointer is used to define the action that will be performed when the button is clicked.
     * The display() method is used to render the button on the screen.
     */
    class Button : public AInteractive {
        public:
            /**
             * @brief Constructs a new Button object with the given title and function pointer.
             *
             * @param[in] title The title of the button.
             * @param[in] func A function pointer that defines the action to be performed when the button is clicked.
             */
            Button(const std::string &title, std::function<void ()> func);

            /**
             * @brief Destroys the Button object.
             */
            ~Button() {}

            /**
             * @brief Renders the button on the screen.
             */
            void display();

        protected:
            /**
             * @brief The function pointer that defines the action to be performed when the button is clicked.
             */
            std::function<void ()> _func;
    };
}

#endif /* !BUTTON_HPP_ */
