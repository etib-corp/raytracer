/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Directionnal
*/

#include "Light/Directionnal.hpp"

Directionnal::Directionnal(const std::shared_ptr<ITexture>& texture)
{
    this->_texture = texture;
}

Directionnal::Directionnal(const Color& color)
{
    this->_texture = std::make_shared<SolidColor>(color);
}

Directionnal::~Directionnal()
{
}

Color Directionnal::emitted(const Ray& ray, const HitRecord& record, double u, double v, const Math::Vector<3>& point) const
{
    if (!record.frontFace)
        return this->_texture->value(u, v, point);
    return Color(0, 0, 0);
}
