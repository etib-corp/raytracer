/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Checker
*/

#include "Texture/Checker.hpp"

Checker::Checker(double scale, std::shared_ptr<ITexture> even, std::shared_ptr<ITexture> odd) : _invScale(1.0 / scale), _even(even), _odd(odd)
{
    this->_type = CHECKER;
}

Checker::Checker(double scale, const Color& even, const Color& odd) : _invScale(1.0 / scale), _even(std::make_shared<SolidColor>(even)), _odd(std::make_shared<SolidColor>(odd))
{
    this->_type = CHECKER;
}

Checker::~Checker()
{
}

Color Checker::value(double u, double v, const Math::Vector<3>& p) const
{
    int x = static_cast<int>(std::floor(p[0] * this->_invScale));
    int y = static_cast<int>(std::floor(p[1] * this->_invScale));
    int z = static_cast<int>(std::floor(p[2] * this->_invScale));

    bool isEven = (x + y + z) % 2 == 0;

    return isEven ? _even->value(u, v, p) : _odd->value(u, v, p);
}