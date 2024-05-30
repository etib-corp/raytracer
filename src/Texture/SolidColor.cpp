/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** SolidColor
*/

#include "Texture/SolidColor.hpp"

SolidColor::SolidColor(const Color& albedo) : _albedo(albedo)
{
    this->_type = SOLIDCOLOR;
}

SolidColor::SolidColor(double r, double g, double b) : _albedo(r, g, b)
{
    this->_type = SOLIDCOLOR;
}

SolidColor::~SolidColor()
{
}

Color SolidColor::value(double u, double v, const Math::Vector<3>& p) const
{
    return _albedo;
}
