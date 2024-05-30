/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** ToolBar
*/

#ifndef TOOLBAR_HPP_
#define TOOLBAR_HPP_

#include "GUI/AGUI.hpp"

namespace GUI {
    /**
     * @class ToolBar
     * @brief A class that represents a toolbar.
     *
     * @details The ToolBar class is a subclass of AGUI and provides a way to display and interact with a toolbar.
     * A toolbar is a graphical control element that contains buttons or icons that allow the user to perform actions.
     *
    */

    /**
     * @brief The ToolBar class represents a graphical user interface toolbar.
     *
     * This class inherits from the AGUI class.
     */
    class ToolBar : public AGUI {
        public:
            /**
             * @brief Constructs a ToolBar object.
             */
            ToolBar();

            /**
             * @brief Destroys the ToolBar object.
             */
            ~ToolBar();

            /**
             * @brief Displays the toolbar.
             */
            void display();

            /**
             * @brief Sets the file functions for the toolbar.
             *
             * @param fileFunctions A map of string keys and function pointers representing file functions.
             */
            void setFileFunctions(std::map<std::string, std::function<void()>> fileFunctions);

            /**
             * @brief Sets the edit functions for the toolbar.
             *
             * @param editFunctions A map of string keys and function pointers representing edit functions.
             */
            void setEditFunctions(std::map<std::string, std::function<void()>> editFunctions);

            /**
             * @brief Sets the help functions for the toolbar.
             *
             * @param helpFunctions A map of string keys and function pointers representing help functions.
             */
            void setHelpFunctions(std::map<std::string, std::function<void()>> helpFunctions);

        protected:
            std::map<std::string, std::function<void()>> _fileFunctions; /**< The map of file functions. */
            std::map<std::string, std::function<void()>> _editFunctions; /**< The map of edit functions. */
            std::map<std::string, std::function<void()>> _helpFunctions; /**< The map of help functions. */
    };
}

#endif /* !TOOLBAR_HPP_ */
