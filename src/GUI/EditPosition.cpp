/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** EditPosition
*/

#include "GUI/EditPosition.hpp"

GUI::EditPosition::EditPosition()
{
    this->_title = "Position";
}

void GUI::EditPosition::display()
{
    if (this->hasToDisplay()) {
        float value[3] = {this->_x, this->_y, this->_z};

        ImGui::InputFloat3(this->_title.c_str(), value);
        this->_x = value[0];
        this->_y = value[1];
        this->_z = value[2];
    }
}

