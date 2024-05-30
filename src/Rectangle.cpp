/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

Math::Rectangle::Rectangle() : _origin(Vector<3>()), _topSide(Vector<3>()), _leftSide(Vector<3>())
{
}

Math::Rectangle::~Rectangle()
{
}

Math::Rectangle::Rectangle(const Math::Vector<3> &origin, const Math::Vector<3> &topSide, const Math::Vector<3> &leftSide)
{
    this->_origin = origin;
    this->_topSide = topSide;
    this->_leftSide = leftSide;
}

void Math::Rectangle::setOrigin(const Math::Vector<3> &origin)
{
    this->_origin = origin;
}

void Math::Rectangle::setTopSide(const Math::Vector<3> &topSide)
{
    this->_topSide = topSide;
}

void Math::Rectangle::setLeftSide(const Math::Vector<3> &leftSide)
{
    this->_leftSide = leftSide;
}

Math::Vector<3> Math::Rectangle::getOrigin() const
{
    return this->_origin;
}

Math::Vector<3> Math::Rectangle::getTopSide() const
{
    return this->_topSide;
}

Math::Vector<3> Math::Rectangle::getLeftSide() const
{
    return this->_leftSide;
}

Math::Vector<3> Math::Rectangle::pointAt(double u, double v) const
{
    return this->_origin + this->_topSide * v + this->_leftSide * u;
}
