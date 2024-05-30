/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** ScrollableChild
*/

#ifndef SCROLLABLECHILD_HPP_
#define SCROLLABLECHILD_HPP_

#include "GUI/ChildPanel.hpp"

namespace GUI {
    /**
     * @class ScrollableChild
     * @brief The ScrollableChild class is a subclass of ChildPanel, which represents a scrollable panel within a GUI.
     *
     * @details This class allows for the creation of a scrollable panel that can contain various elements.
     *
     * @author Nathan Maillot
     * @version 1.0
     * @date 2024
     */
    class ScrollableChild : public ChildPanel {
        public:
            /**
             * @brief Constructor for the ScrollableChild class.
             *
             * @param[in] title The title of the scrollable panel.
             */
            ScrollableChild(const std::string &title);

            /**
             * @brief Destructor for the ScrollableChild class.
             */
            ~ScrollableChild() {}

            /**
             * @brief Displays the contents of the scrollable panel.
             */
            void display();
    };
}

#endif /* !SCROLLABLECHILD_HPP_ */
