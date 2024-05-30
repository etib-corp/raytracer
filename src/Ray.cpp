/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Ray
*/

#include "Ray.hpp"

Ray::Ray() : _point(Math::Vector<3>()), _direction(Math::Vector<3>())
{
}

Ray::Ray(Math::Vector<3> point, Math::Vector<3> direction) : _point(point), _direction(direction)
{
}

Math::Vector<3> Ray::getPoint() const
{
    return this->_point;
}

Math::Vector<3> Ray::getDirection() const
{
    return this->_direction;
}

void Ray::setPoint(Math::Vector<3> point)
{
    this->_point = point;
}

void Ray::setDirection(Math::Vector<3> direction)
{
    this->_direction = direction;
}

Math::Vector<3> Ray::at(double t) const
{
    return this->_point + this->_direction * t;
}