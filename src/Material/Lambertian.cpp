/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Lambertian
*/

#include "Material/Lambertian.hpp"

Lambertian::Lambertian(const Color& albedo)
{
    this->_albedo = albedo;
    this->_type = LAMBERTIAN;
    this->_texture = std::make_shared<SolidColor>(albedo);
    typeSet("Lambertian");
    hasColorSet();
}

Lambertian::Lambertian(std::shared_ptr<ITexture> texture)
{
    this->_texture = texture;
    typeSet("Lambertian");
    hasTextureSet();
    this->_type = LAMBERTIAN;
}

Lambertian::~Lambertian()
{
}

bool Lambertian::scatter(const Ray& ray, const HitRecord& hit, Color& attenuation, Ray& scattered) const
{
    Math::Vector<3> direction = hit.normal + randomUnitVector();
    if (direction.nearZero())
        direction = hit.normal;
    scattered = Ray(hit.point, direction);
    attenuation = this->_texture->value(hit.u, hit.v, hit.point);
    return true;

}