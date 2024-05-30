/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Diffuse
*/

#include "Light/Diffuse.hpp"

Diffuse::Diffuse(const std::shared_ptr<ITexture>& texture)
{
    this->_texture = texture;
}

Diffuse::Diffuse(const Color& color)
{
    this->_texture = std::make_shared<SolidColor>(color);
}

Diffuse::~Diffuse()
{
}

Color Diffuse::emitted(const Ray& ray, const HitRecord& record, double u, double v, const Math::Vector<3>& point) const
{
    return this->_texture->value(u, v, point);
}