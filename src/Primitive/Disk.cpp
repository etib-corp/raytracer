/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Disk
*/

#include "Primitive/Disk.hpp"

Disk::Disk()
{
    this->_type = DISK;
}

Disk::Disk(const Math::Vector<3> center, const Math::Vector<3> &normal, double radius, std::shared_ptr<IMaterial> material) : _center(center), _normal(normal), _radius(radius)
{
    this->_type = DISK;
    this->_material = material;
}

bool Disk::hit(const Ray &ray, const Interval &ray_t, HitRecord &record) const
{
    double t = this->_normal.dot(this->_center - ray.getPoint()) / this->_normal.dot(ray.getDirection());
    if (t < ray_t.getMin() || t > ray_t.getMax())
        return false;
    Math::Vector<3> p = ray.at(t);
    Math::Vector<3> d = p - this->_center;
    if (d.length() > this->_radius)
        return false;
    record.t = t;
    record.point = p;
    record.setFaceNormal(ray, this->_normal);
    record.material = this->_material;
    Disk::getDiskUV(p, record.u, record.v);
    return true;
}

inline Math::Vector<3> Disk::getCenter() const
{
    return this->_center;
}