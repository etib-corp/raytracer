/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** AInteractive
*/

#ifndef AINTERACTIVE_HPP_
#define AINTERACTIVE_HPP_

#include "AGUI.hpp"

namespace GUI {
    /**
     * @class AInteractive
     * @brief Abstract base class for interactive GUI elements.
     *
     * This class provides a basic interface for interactive elements, including a virtual display() method that must be implemented by derived classes.
     *
     * @author Julien Ferdinand
     */
    class AInteractive : public AGUI {
        public:
            /**
             * @brief Destructor for AInteractive.
             *
             * The default destructor is provided to ensure proper cleanup of resources.
             */
            ~AInteractive() = default;

            /**
             * @brief Virtual method to display the interactive element.
             *
             * This method must be implemented by derived classes to provide the specific display logic.
             *
             * @return void
             */
            virtual void display() = 0;

            /**
             * @brief Get the title of the interactive element.
             *
             * This method returns the title of the interactive element as a string.
             *
             * @return std::string The title of the interactive element.
             */
            std::string getTitle() const;

            /**
             * @brief Sets the title of the interactive element.
             *
             * @param title The title to set.
             */
            void setTitle(const std::string title) { this->_title = title; }

        protected:
            /**
             * @brief Protected member variable to store the title of the interactive element.
             *
             * This member variable is used to store the title of the interactive element.
             */
            std::string _title;
    };

}

#endif /* !AINTERACTIVE_HPP_ */
