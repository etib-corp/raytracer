/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** RadioButton
*/

#include "GUI/RadioButton.hpp"

GUI::RadioButton::RadioButton(const std::string &title)
{
    this->_title = title;
    this->_active = false;
}

void GUI::RadioButton::display()
{
    if (this->hasToDisplay()) {
        if (ImGui::RadioButton(this->_title.c_str(), this->_active)) {
            this->_active = !this->_active;
        }
    }
}

bool GUI::RadioButton::isActive() const
{
    return this->_active;
}

void GUI::RadioButton::setActive(bool active)
{
    this->_active = active;
}
