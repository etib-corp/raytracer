/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** EditPosition
*/

#ifndef EDITPOSITION_HPP_
#define EDITPOSITION_HPP_

#include "GUI/AEditDouble3.hpp"

namespace GUI {
    /**
     * @brief The EditPosition class is a subclass of AEditDouble3 and is used to edit a 3D position.
     *
     * It inherits the functionality of AEditDouble3 and provides a specific implementation for editing a 3D position.
     *
     * @see AEditDouble3
     */
    class EditPosition : public AEditDouble3 {
        public:
            /**
             * @brief Default constructor for EditPosition.
             */
            EditPosition();

            /**
             * @brief Destructor for EditPosition.
             */
            ~EditPosition() {}

            /**
             * @brief Displays the EditPosition object.
             */
            void display();
    };
}

#endif /* !EDITPOSITION_HPP_ */
