/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** AEditDouble3
*/

#include "GUI/AEditDouble3.hpp"

float GUI::AEditDouble3::getX() const
{
    return this->_x;
}

float GUI::AEditDouble3::getY() const
{
    return this->_y;
}

float GUI::AEditDouble3::getZ() const
{
    return this->_z;
}

void GUI::AEditDouble3::setX(float value)
{
    this->_x = value;
}

void GUI::AEditDouble3::setY(float value)
{
    this->_y = value;
}

void GUI::AEditDouble3::setZ(float value)
{
    this->_z = value;
}


