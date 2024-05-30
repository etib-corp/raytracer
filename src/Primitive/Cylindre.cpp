/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Cylindre
*/

#include "Primitive/Cylindre.hpp"

Cylindre::Cylindre()
{
    this->_type = CYLINDER;
}

Cylindre::Cylindre(const Math::Vector<3>& center, double depth, double radius, std::shared_ptr<IMaterial> material) : _depth(depth), _radius(radius) , _center(center), _topDisk(Math::Vector<3>({0, depth, 0}) + center, Math::Vector<3>({0, 1, 0}), radius, material), _bottomDisk(center, Math::Vector<3>({0, -1, 0}), radius, material)
{
    this->_type = CYLINDER;
    this->_material = material;
}

Cylindre::~Cylindre()
{
}

bool Cylindre::hit(const Ray &ray, const Interval &ray_t, HitRecord &record) const
{
    if ((ray.getPoint()[1] > (this->_center[1] + this->_depth) && this->_topDisk.hit(ray, ray_t, record)) || (ray.getPoint()[1] < this->_center[1] && this->_bottomDisk.hit(ray, ray_t, record))) {
        return true;
    }
    const Math::Vector<3> origin = ray.getPoint();
    const Math::Vector<3> direction = ray.getDirection();
    Math::Vector<3> oc = origin - this->_center;
    const double a = pow(direction[0], 2.0) + pow(direction[2], 2.0);
    const double b = 2.0 * (direction[0] * oc[0]) + 2.0 * (direction[2] * oc[2]);
    const double c = pow(oc[0], 2.0) + pow(oc[2], 2.0) - pow(this->_radius, 2.0);
    const double delta = b * b - 4 * a * c;

    if (delta < 0) {
        return false;
    }
    double t1 = (-b - sqrt(delta)) / (2 * a);
    double t2 = (-b + sqrt(delta)) / (2 * a);
    double y = origin[1] + t1 * direction[1];

    // Intersection avec les faces supérieure et inférieure du cylindre
    if (y < this->_center[1] || y > this->_center[1] + this->_depth) {
        double y2 = origin[1] + t2 * direction[1];
        if (y2 < this->_center[1] || y2 > this->_center[1] + (this->_depth / 2.0)) {
            return false;
        }
        t1 = t2;
    }

    double t_min = std::min(t1, t2);
    double t_max = std::max(t1, t2);

    if (!ray_t.surrounds(t_min) && !ray_t.surrounds(t_max)) {
        return false;
    }

    // Intersection avec les côtés du cylindre
    double t_hit = t_min;
    if (!ray_t.surrounds(t_min)) {
        t_hit = t_max;
    }

    Math::Vector<3> hit_point = ray.at(t_hit);
    Math::Vector<3> outwardNormal = (hit_point - Math::Vector<3>({this->_center[0], hit_point[1], this->_center[2]})).normalize();

    // Vérification si le point d'intersection est sur le côté du cylindre
    // if (fabs(hit_point[1] - this->_center[1]) <= this->_depth) {
        record.t = t_hit;
        record.u = 0.5 + atan2(outwardNormal[2], outwardNormal[0]) / (2 * M_PI);
        record.v = 0.5 - asin(outwardNormal[1]) / M_PI;
        record.material = this->_material;
        record.point = hit_point;
        record.setFaceNormal(ray, outwardNormal);
        return true;

    return false;
}
