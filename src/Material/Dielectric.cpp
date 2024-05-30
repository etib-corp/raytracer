/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Dielectric
*/

#include "Material/Dielectric.hpp"

static double reflectance(double cosine, double ref_idx)
{
    double r0 = (1 - ref_idx) / (1 + ref_idx);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - cosine), 5);
}

Dielectric::Dielectric(double refractive_index)
{
    this->_refractive_index = refractive_index;
    typeSet("Dielectric");
    this->_type = DIELECTRIC;
}

Dielectric::~Dielectric()
{
}

bool Dielectric::scatter(const Ray &ray_in, const HitRecord &rec, Color &attenuation, Ray &scattered) const
{
    attenuation = Color(1.0, 1.0, 1.0);
    double ri = rec.frontFace ? (1.0 / this->_refractive_index) : this->_refractive_index;

    Math::Vector<3> unit_direction = ray_in.getDirection().unit_vector();
    double cos_theta = fmin((unit_direction * -1.0).dot(rec.normal), 1.0);
    double sin_theta = sqrt(1.0 - cos_theta * cos_theta);

    bool cannot_refract = ri * sin_theta > 1.0;
    Math::Vector<3> direction;

    if (cannot_refract || reflectance(cos_theta, ri) > random_double())
        direction = reflect(unit_direction, rec.normal);
    else
        direction = refract(unit_direction, rec.normal, ri);

    scattered = Ray(rec.point, direction);
    return true;
}
