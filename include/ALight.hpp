/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** ALight
*/

#pragma once

#include "AObject.hpp"
#include "Color.hpp"

class ALight : public AObject {
    public:
        virtual ~ALight() = default;
  
        Color getColor() const;
        void setColor(const Color &color);

    protected:
        Color _color;
        Math::Vector<3> _direction;
};

