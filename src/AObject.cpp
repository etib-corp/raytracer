/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** AObject
*/

#include "AObject.hpp"

void AObject::setPosition(const Math::Vector<3> &pos)
{
    this->_position = pos;
}

Math::Vector<3> AObject::getPosition() const
{
    return this->_position;
}
