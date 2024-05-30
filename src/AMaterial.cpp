/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** AMaterial
*/

#include "AMaterial.hpp"

Color AMaterial::emitted(const Ray& ray, const HitRecord& record, double u, double v, const Math::Vector<3>& point) const
{
    return Color(0, 0, 0);
}

bool AMaterial::scatter(const Ray &ray, const HitRecord &hit, Color &attenuation, Ray &scattered) const
{
    return false;
}