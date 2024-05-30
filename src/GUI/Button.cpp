/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Button
*/

#include "GUI/Button.hpp"

GUI::Button::Button(const std::string &title, std::function<void ()> func)
{
    this->_title = title;
    this->_func = func;
}

void GUI::Button::display()
{
    if (this->hasToDisplay()) {
        if (ImGui::Button(this->_title.c_str())) {
            this->_func();
        }
    }
}

