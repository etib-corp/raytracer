
/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Cone
*/

#include "Primitive/Cone.hpp"

Cone::Cone() : _baseCenter(Math::Vector<3>()), _radius(0), _height(1)
{
    this->_baseCenter += this->_position;
    this->_type = CONE;
}

Cone::Cone(const Math::Vector<3>& baseCenter, double height, double radius, std::shared_ptr<IMaterial> material) : _baseCenter(baseCenter), _radius(radius), _height(height), _base(baseCenter, Math::Vector<3>({0, 1, 0}), radius / (height / radius), material)
{
    this->_baseCenter += this->_position;
    this->_angle = (atan(this->_radius / height));
    this->_type = CONE;
    this->_material = material;
}

double cos2(double x)
{
    return (1.0 + cos(2.0 * x) / 2.0);
}

bool Cone::hit(const Ray &ray, const Interval& ray_t, HitRecord &record) const
{
    if (ray.getPoint()[1] < this->_baseCenter[1] && this->_base.hit(ray, ray_t, record)) {
        return true;
    }
    Math::Vector<3> origin = ray.getPoint();
    Math::Vector<3> direction = ray.getDirection().normalize();
    double A = origin[0] - this->_baseCenter[0];
    double B = origin[2] - this->_baseCenter[2];
    double D = origin[1] - this->_baseCenter[1];

    double thet = SQUARE(this->_radius / this->_height);

    double a = (SQUARE(direction[0]) + SQUARE(direction[2]) - SQUARE(thet) * SQUARE(direction[1]));
    double b = (2 * A * direction[0]) + (2 * B * direction[2]) + (2 * SQUARE(thet) * (this->_height - D) * direction[1]);
    double c = (SQUARE(A) + SQUARE(B) - SQUARE(thet) * SQUARE(this->_height - D));

    double delta = b * b - 4 * a * c;

    if (delta < 0) {
        return false;
    }

    if (delta > 0) {
        double k1 = (-b - sqrt(delta)) / (2 * a);
        double k2 = (-b + sqrt(delta)) / (2 * a);
        double k = (k1 < k2) ? k1 : k2;
        double y = origin[1] + k * direction[1];
        if (y < this->_baseCenter[1] || y > this->_baseCenter[1] + this->_height) {
            return false;
        }
        if (k < ray_t.getMin() || k > ray_t.getMax()) {
            return false;
        }
        record.t = k;
        record.point = ray.at(k);
        record.material = this->_material;
        record.setFaceNormal(ray, direction);
        Cone::getConeUV(record.point, record.u, record.v);
        return true;
    }
    return false;
}
