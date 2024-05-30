/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** ChildPanel
*/

#ifndef CHILDPANEL_HPP_
#define CHILDPANEL_HPP_

#include "GUI/AInteractive.hpp"

namespace GUI {
    /**
     * @class ChildPanel
     * @brief The ChildPanel class is a subclass of AInteractive and represents a panel that can contain other interactive elements.
     *
     * @details The ChildPanel class allows adding other interactive elements to it and displaying them.
     */
    class ChildPanel : public AInteractive {
        public:
            /**
             * @brief Default constructor for the ChildPanel class.
             */
            ChildPanel();

            /**
             * @brief Constructor for the ChildPanel class with a title parameter.
             *
             * @param[in] title The title of the panel.
             */
            ChildPanel(const std::string &title);

            /**
             * @brief Destructor for the ChildPanel class.
             */
            ~ChildPanel() {}

            /**
             * @brief Adds an interactive element to the panel.
             *
             * @param[in] interactive The interactive element to be added.
             */
            void addInteractive(AInteractive &interactive);

            /**
             * @brief Displays the panel and its contained interactive elements.
             */
            void display();

        protected:
            /**
             * @brief A vector to store the interactive elements contained in the panel.
             */
            std::vector<AInteractive *> _children;
    };
}

#endif /* !CHILDPANEL_HPP_ */
