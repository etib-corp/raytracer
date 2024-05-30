/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Metal
*/

#include "Material/Metal.hpp"

Metal::Metal(const Color& albedo, double fuzz)
{
    this->_albedo = albedo;
    this->_fuzz = fuzz < 1 ? fuzz : 1;
    typeSet("Metal");
    hasColorSet();
    this->_type = METAL;
}

Metal::~Metal()
{
}

bool Metal::scatter(const Ray& ray, const HitRecord& hit, Color& attenuation, Ray& scattered) const
{
    Math::Vector<3> reflected = reflect(ray.getDirection().normalize(), hit.normal);
    reflected = reflected.unit_vector() + randomInUnitSphere() * this->_fuzz;
    scattered = Ray(hit.point, reflected);
    attenuation = this->_albedo;
    return (scattered.getDirection().dot(hit.normal) > 0);
}
