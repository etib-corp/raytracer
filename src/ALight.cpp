/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** ALight
*/

#include "ALight.hpp"

Color ALight::getColor() const
{
    return this->_color;
}

void ALight::setColor(const Color &color)
{
    this->_color = color;
}
