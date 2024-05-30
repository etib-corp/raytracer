/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** AGUI
*/

#ifndef AGUI_HPP_
#define AGUI_HPP_

#include "IGUI.hpp"

#include "Primitive/ObjectsList.hpp"

namespace GUI {
    /**
     * @class AGUI
     * @brief The AGUI class is a base class for all graphical user interfaces.
     *
     * It provides basic functionality for updating, displaying, and initializing the GUI.
     *
     * @author Nathan Maillot
     * @date 2024
     */
    class AGUI : public IGUI {
        public:
            /**
             * @brief Destructor for the AGUI class.
             *
             * It is a virtual destructor to allow for polymorphic destruction.
             */
            virtual ~AGUI() = default;

            /**
             * @brief Updates the GUI.
             *
             * This function should be called regularly to update the state of the GUI.
             */
            void update();

            /**
             * @brief Displays the GUI.
             *
             * This function should be called to render the GUI on the screen.
             * It is a pure virtual function that must be implemented by derived classes.
             */
            virtual void display() = 0;

            /**
             * @brief Initializes the GUI.
             *
             * This function sets up the GUI with the provided window, clock, and world objects.
             *
             * @param window The window on which the GUI will be displayed.
             * @param clock The clock used to track time for animations and updates.
             * @param world The world object containing all the objects in the scene.
             */
            void init(sf::RenderWindow &window, sf::Clock &clock, ObjectsList &world);

            /**
             * @brief Checks if the GUI should be displayed.
             *
             * This function returns true if the GUI should be displayed, and false otherwise.
             *
             * @return True if the GUI should be displayed, false otherwise.
             */
            bool hasToDisplay();

            /**
             * @brief Sets whether the GUI should be displayed.
             *
             * This function sets the display flag to true or false, depending on the parameter.
             *
             * @param display True to display the GUI, false to hide it.
             */
            void setDisplay(bool display);

        protected:
            /**
             * @brief Flag indicating whether the GUI should be displayed.
             *
             * This flag is used to control the visibility of the GUI.
             */
            bool _display = false;

            /**
             * @brief Pointer to the window on which the GUI will be displayed.
             *
             * This pointer is used to render the GUI on the screen.
             */
            sf::RenderWindow *_window;

            /**
             * @brief Pointer to the clock used to track time for animations and updates.
             *
             * This pointer is used to synchronize the GUI with the game loop.
             */
            sf::Clock *_clock;

            /**
             * @brief Pointer to the world object containing all the objects in the scene.
             *
             * This pointer is used to interact with the game world and update the GUI accordingly.
             */
            ObjectsList *_world;
    };
}
#endif /* !AGUI_HPP_ */