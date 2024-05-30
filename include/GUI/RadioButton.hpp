/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** RadioButton
*/

#ifndef RADIOBUTTON_HPP_
#define RADIOBUTTON_HPP_

#include "GUI/AInteractive.hpp"

namespace GUI {
    /**
     * @class RadioButton
     * @brief The RadioButton class is a subclass of AInteractive and represents a radio button in the GUI.
     *
     * A radio button is a graphical control element that allows the user to select
     * one of several options. Only one radio button in a group can be selected at a time.
     *
     * @author Your Name nathan.maillot@epitech.eu
     */
    class RadioButton : public AInteractive {
        public:
            /**
             * @brief Constructs a RadioButton object with the given title.
             *
             * @param[in] title The title of the radio button.
             */
            RadioButton(const std::string &title);

            /**
             * @brief Destructs the RadioButton object.
             */
            ~RadioButton() {}

            /**
             * @brief Displays the radio button on the screen.
             */
            void display();

            /**
             * @brief Checks if the radio button is currently active.
             *
             * @return True if the radio button is active, false otherwise.
             */
            bool isActive() const;

            /**
             * @brief Sets the active state of the radio button.
             *
             * @param[in] active True to set the radio button as active, false otherwise.
             */
            void setActive(bool active);

        protected:
            /**
             * @brief Indicates if the radio button is currently active.
             */
            bool _active;
    };
}

#endif /* !RADIOBUTTON_HPP_ */
