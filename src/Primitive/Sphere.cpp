/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Sphere
*/

#include "Primitive/Sphere.hpp"

Sphere::Sphere() : _center(Math::Vector<3>()), _radius(0)
{
    this->_type = SPHERE;
}

Sphere::Sphere(const Math::Vector<3> &center, double radius, std::shared_ptr<IMaterial> material) : _center(center), _radius(fmax(0, radius))
{
    this->_type = SPHERE;
    this->_material = material;
}

bool Sphere::hit(const Ray &ray, const Interval& ray_t, HitRecord &record) const
{
    const Math::Vector<3> origin = ray.getPoint();
    const Math::Vector<3> direction = ray.getDirection();
    const Math::Vector<3> oc = this->_center - origin;
    double a = direction.length_squared();
    double h = direction.dot(oc);
    double c = oc.length_squared() - this->_radius * this->_radius;
    const double delta = h * h - a * c;

    if (delta < 0) {
        return false;
    }
    double sqrtDelta = sqrt(delta);

    double root = (h - sqrtDelta) / a;

    if (!ray_t.surrounds(root)) {
        root = (h + sqrtDelta) / a;
        if (!ray_t.surrounds(root)) {
            return false;
        }
    }
    record.t = root;
    record.point = ray.at(record.t);
    Math::Vector<3> outwardNormal = (record.point - this->_center) / this->_radius;
    record.setFaceNormal(ray, outwardNormal);
    Sphere::getSphereUV(outwardNormal, record.u, record.v);
    record.material = this->_material;
    return true;
}

// double Sphere::hits(const Ray &ray) const
// {
//     const Math::Vector<3> origin = ray.getPoint();
//     const Math::Vector<3> direction = ray.getDirection();
//     const Math::Vector<3> oc = this->_center - origin;
//     double a = direction.dot(direction);
//     double h = direction.dot(oc);
//     double c = (oc).dot(oc) - this->_radius * this->_radius;
//     const double delta = h * h - a * c;

//     if (delta < 0) {
//         return -1.0;
//     } else {
//         return (h - sqrt(delta)) / a;
//     }
// }


Math::Vector<3> Sphere::getCenter() const
{
    return this->_center;
}
