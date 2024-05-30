/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Color
*/

#include "Color.hpp"

Color::Color(double r, double g, double b, double a)
{
    this->red = r;
    this->green = g;
    this->blue = b;
    this->alpha = a;
}

Color::Color(const Color& color)
{
    this->red = color.red;
    this->green = color.green;
    this->blue = color.blue;
    this->alpha = color.alpha;
}

Color::~Color()
{
}

void Color::write(std::ostream &os)
{
    static const Interval intensity(0.0, 0.999);
    os << static_cast<int>(intensity.clamp(Color::linearToGamma(this->red)) * 256) << ' '
       << static_cast<int>(intensity.clamp(Color::linearToGamma(this->green)) * 256) << ' '
       << static_cast<int>(intensity.clamp(Color::linearToGamma(this->blue)) * 256) << '\n';
}

double Color::linearToGamma(double linear)
{
    if (linear > 0)
        return sqrt(linear);
    return 0;
}

Color Color::operator*(double scalar) const
{
    return Color(this->red * scalar, this->green * scalar, this->blue * scalar, this->alpha);
}

Color Color::operator*(const Color& color) const
{
    return Color(this->red * color.red, this->green * color.green, this->blue * color.blue, this->alpha);
}

Color Color::operator+(const Color& color) const
{
    return Color(this->red + color.red, this->green + color.green, this->blue + color.blue, this->alpha);
}
