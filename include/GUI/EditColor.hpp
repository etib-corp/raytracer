/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** EditColor
*/

#ifndef EDITCOLOR_HPP_
#define EDITCOLOR_HPP_

#include "GUI/AEditDouble3.hpp"

namespace GUI {
    /**
     * @class EditColor
     * @brief A subclass of AEditDouble3 for editing color values.
     *
     * This class is a subclass of AEditDouble3 and is used for editing color values.
     * It inherits the basic functionality of AEditDouble3 and adds specific behavior for color editing.
     *
     * @author Nathan Maillot
     * @version 1.0
     * @date 2024
     */
    class EditColor : public AEditDouble3 {
        public:
            /**
             * @brief Default constructor for EditColor.
             *
             * This constructor initializes an instance of EditColor.
             *
             * @author Nathan Maillot
             * @version 1.0
             * @date 2024
             */
            EditColor();

            /**
             * @brief Constructs an EditColor object with the specified title.
             *
             * @param title The title of the EditColor object.
             */
            EditColor(const std::string &title);

            /**
             * @brief Destructor for EditColor.
             *
             * This destructor cleans up any resources allocated by EditColor.
             *
             * @author Nathan Maillot
             * @version 1.0
             * @date 2024
             */
            ~EditColor() {}

            /**
             * @brief Displays the color values being edited.
             *
             * This method displays the color values being edited by EditColor.
             * It is a virtual method that can be overridden by subclasses.
             *
             * @author Nathan Maillot
             * @version 1.0
             * @date 2024
             */
            void display();
    };

}

#endif /* !EDITCOLOR_HPP_ */
