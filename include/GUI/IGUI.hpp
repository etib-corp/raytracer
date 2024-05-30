/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** GUI
*/

#ifndef IGUI_HPP_
#define IGUI_HPP_

#include "raytracer.hpp"

#include "imgui.h"
#include "imgui-SFML.h"

#include "Primitive/ObjectsList.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace GUI {
    /**
     * @class IGUI
     * @brief Interface for the Graphical User Interface (GUI)
     *
     * This interface provides a basic structure for the GUI, allowing for the
     * implementation of different GUI systems.
     */
    class IGUI {
        public:
            /**
             * @brief Virtual destructor
             *
             * This virtual destructor ensures proper memory management when
             * dealing with polymorphic objects.
             */
            virtual ~IGUI() = default;

            /**
             * @brief Update the GUI
             *
             * This method should be implemented by derived classes to update
             * the state of the GUI.
             */
            virtual void update() = 0;

            /**
             * @brief Display the GUI
             *
             * This method should be implemented by derived classes to display
             * the GUI on the screen.
             */
            virtual void display() = 0;

            /**
             * @brief Check if the GUI should be displayed
             *
             * This method should be implemented by derived classes to check
             * if the GUI should be displayed or not.
             *
             * @return True if the GUI should be displayed, false otherwise.
             */
            virtual bool hasToDisplay() = 0;

            /**
             * @brief Initializes the GUI.
             *
             * This function is responsible for initializing the GUI by setting up the window, clock, and world objects.
             *
             * @param window The SFML render window.
             * @param clock The SFML clock.
             * @param world The list of objects in the world.
             */
            virtual void init(sf::RenderWindow &window, sf::Clock &clock, ObjectsList &world) = 0;

            /**
             * @brief Set whether the GUI should be displayed
             *
             * This method should be implemented by derived classes to set
             * whether the GUI should be displayed or not.
             *
             * @param display True to display the GUI, false otherwise.
             */
            virtual void setDisplay(bool display) = 0;
    };
}

#endif /* !GUI_HPP_ */
