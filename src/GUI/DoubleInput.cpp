/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** DoubleInput
*/

#include "GUI/DoubleInput.hpp"

GUI::DoubleInput::DoubleInput(const std::string &title)
{
    this->_title = title;
    this->_value = 0;
}

void GUI::DoubleInput::display()
{
    if (this->hasToDisplay()) {
        ImGui::InputFloat(this->_title.c_str(), &this->_value);
    }
}

double GUI::DoubleInput::getValue() const
{
    return this->_value;
}

void GUI::DoubleInput::setValue(double value)
{
    this->_value = value;
}
