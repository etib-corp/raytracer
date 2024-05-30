/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** EditColor
*/

#include "GUI/EditColor.hpp"

GUI::EditColor::EditColor()
{
    this->_title = "Color";
    this->_x = 0;
    this->_y = 0;
    this->_z = 0;
}

GUI::EditColor::EditColor(const std::string &title)
{
    this->_title = title;
    this->_x = 0;
    this->_y = 0;
    this->_z = 0;
}

void GUI::EditColor::display()
{
    if (this->hasToDisplay()) {
        float value[3] = {this->_x, this->_y, this->_z};
        ImGui::ColorEdit3(this->_title.c_str(), value);
        this->_x = value[0];
        this->_y = value[1];
        this->_z = value[2];
    }
}
