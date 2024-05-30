/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Plan
*/

#include "Primitive/Plan.hpp"

Plan::Plan()
{
    this->_type = PLANE;
}

Plan::Plan(const std::string &axis, double value, const Color& color) : _axis(axis), _value(value), _material(std::make_shared<Lambertian>(std::make_shared<SolidColor>(color)))
{
    if (axis != "x" && axis != "y" && axis != "z")
        throw PlanError("Invalid axis \"" + axis + "\"");
    this->_type = PLANE;
}

Plan::Plan(const std::string &axis, double value, const std::shared_ptr<IMaterial> &material) : _axis(axis), _value(value), _material(material)
{
    if (axis != "x" && axis != "y" && axis != "z")
        throw PlanError("Invalid axis \"" + axis + "\"");
    this->_type = PLANE;
}

Plan::~Plan()
{
}

bool Plan::hit(const Ray &ray, const Interval &ray_t, HitRecord &record) const
{
    int ind = this->_axis == "x" ? 0 : this->_axis == "y" ? 1 : 2;
    double t = (this->_value - ray.getPoint()[ind]) / (ray.getDirection()[ind] != 0 ? ray.getDirection()[ind] : 1e-6);

    if (t < ray_t.getMin() || t > ray_t.getMax())
        return false;

    Math::Vector<3> n = Math::Vector<3>({0, 1, 0});
    record.point = ray.at(t);
    record.t = t;
    record.setFaceNormal(ray, n);
    record.material = this->_material;
    this->getPlanUV(record.point, record.u, record.v);
    return true;
}
