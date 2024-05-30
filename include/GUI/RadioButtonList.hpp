/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** RadioButtonList
*/

#ifndef RADIOBUTTONLIST_HPP_
#define RADIOBUTTONLIST_HPP_

#include "GUI/RadioButton.hpp"

namespace GUI {
    /**
     * @class RadioButtonList
     * @brief A class that represents a list of radio buttons.
     *
     * @details The RadioButtonList class is a subclass of AInteractive and
     *          provides a way to display and interact with a list of radio buttons.
     *
     * @param title The title of the radio button list.
     * @param titles A vector of strings representing the titles of the radio buttons.
     */
    class RadioButtonList : public AInteractive {
        public:
            /**
             * @brief Constructor for the RadioButtonList class.
             *
             * @param title The title of the radio button list.
             * @param titles A vector of strings representing the titles of the radio buttons.
             */
            RadioButtonList(std::string title, std::vector<std::string> titles);

            /**
             * @brief Destructor for the RadioButtonList class.
             */
            ~RadioButtonList() {}

            /**
             * @brief Displays the radio button list on the screen.
             */
            void display();

            /**
             * @brief Updates the state of the radio button list.
             */
            void update();

            /**
             * @brief Initializes the radio button list for rendering.
             *
             * @param window The SFML window to render the radio button list on.
             * @param clock The SFML clock to track time.
             * @param world The ObjectsList containing all objects in the scene.
             */
            void init(sf::RenderWindow &window, sf::Clock &clock, ObjectsList &world);

            /**
             * @brief Gets the value of the currently checked radio button.
             *
             * @return The value of the currently checked radio button as a string.
             */
            std::string getChecked() const;

        protected:
            /**
             * @brief A vector containing all the radio buttons in the list.
             */
            std::vector<RadioButton *> _children;

            /**
             * @brief A pointer to the last checked radio button in the list.
             */
            std::vector<RadioButton *>::iterator _lastChecked = _children.end();
    };
}

#endif /* !RADIOBUTTONLIST_HPP_ */
