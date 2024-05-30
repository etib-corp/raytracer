/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Interval
*/

#include "Interval.hpp"

const Interval Interval::empty = Interval(+infinity, -infinity);
const Interval Interval::universe = Interval(-infinity, +infinity);

Interval::Interval()  : min(+infinity), max(-infinity)
{
}

Interval::Interval(double min, double max) : min(min), max(max)
{
}

Interval::~Interval()
{
}

double Interval::getMin() const
{
    return this->min;
}

double Interval::getMax() const
{
    return this->max;
}

void Interval::setMin(double min)
{
    this->min = min;
}

void Interval::setMax(double max)
{
    this->max = max;
}

double Interval::size() const
{
    return this->max - this->min;
}

bool Interval::contains(double value) const
{
    return value >= this->min && value <= this->max;
}

bool Interval::surrounds(double value) const
{
    return value > this->min && value < this->max;
}

double Interval::clamp(double value) const
{
    return std::clamp(value, this->min, this->max);
}