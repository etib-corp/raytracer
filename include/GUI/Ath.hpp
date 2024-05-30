/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Ath
*/

#ifndef ATH_HPP_
#define ATH_HPP_

#include "GUI/AGUI.hpp"

#include "GUI/ToolBar.hpp"

namespace GUI {
    /**
     * @brief The ATH class is an abstract class that serves as the base class for all Athena GUI elements.
     *
     * It provides the basic functionality for creating and managing GUI elements, such as panels, toolbars, and controls.
     * The ATH class is designed to be inherited by other GUI classes, allowing for a hierarchical structure of GUI elements.
     *
     * The ATH class provides a number of methods for creating and managing GUI elements, such as addPanel(), addToolBar(), and addControl().
     * These methods allow developers to easily create complex GUI interfaces by simply calling a series of methods.
     *
     * In addition, the ATH class provides a display() method, which is responsible for drawing all of the GUI elements on the screen.
     * This method is called automatically by the Athena engine, ensuring that the GUI elements are always up to date.
     *
     * Overall, the ATH class provides a powerful and flexible framework for creating GUI elements in Athena, making it an essential component of any GUI-based application.
     */
    class ATH : public AGUI {
        public:
            /**
             * @brief The default constructor for the ATH class.
             */
            ATH() {}

            /**
             * @brief The default destructor for the ATH class.
             */
            ~ATH() {}

            /**
             * @brief This method is responsible for drawing all of the GUI elements on the screen.
             *
             * It is called automatically by the Athena engine, ensuring that the GUI elements are always up to date.
             */
            void display();

        protected:
            /**
             * @brief A pointer to the main panel of the GUI.
             */
            IGUI *_mainPanel;

            /**
             * @brief A pointer to the tool bar of the GUI.
             */
            ToolBar *_toolBar;

            /**
             * @brief A pointer to the control panel of the GUI.
             */
            IGUI *_controlPanel;

            /**
             * @brief A pointer to a temporary panel used for holding GUI elements temporarily.
             */
            IGUI *_tempPanel;
    };
}

#endif /* !ATH_HPP_ */
