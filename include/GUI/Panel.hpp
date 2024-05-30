/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Panel
*/

#ifndef PANEL_HPP_
#define PANEL_HPP_

#include "GUI/AInteractive.hpp"

namespace GUI {
    class Panel : public AGUI {
        public:
            /**
             * @brief Constructs a Panel with the given title.
             *
             * @param[in] title The title of the panel.
             */
            Panel(const std::string &title);
            Panel();

            /**
             * @brief Destructor for the Panel class.
             */
            ~Panel() {}

            /**
            * @brief Adds an interactive element to the panel.
            *
            * @param[in] interactive The interactive element to be added.
            */
            void addInteractive(AInteractive &interactive);

            /**
             * @brief Displays the panel and its interactive elements.
             */
            void display();

        protected:
            std::string _title; // The title of the panel.
            std::vector<AInteractive *> _children; // The children stored in the panel.
    };

}

#endif /* !PANEL_HPP_ */
