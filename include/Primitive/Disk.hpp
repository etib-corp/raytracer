/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Disk
*/

#pragma once

#include "raytracer.hpp"

#include "Vector.hpp"
#include "Ray.hpp"
#include "APrimitive.hpp"

class Disk : public APrimitive {
    public:
        Disk();
        Disk(const Math::Vector<3> center, const Math::Vector<3> &normal, double radius, std::shared_ptr<IMaterial> material = nullptr);
        ~Disk() = default;

        bool hit(const Ray &ray, const Interval &ray_t, HitRecord &record) const override;

        static inline void getDiskUV(const Math::Vector<3>& p, double& u, double& v)
        {
            double phi = atan2(p[0], p[2]);
            double r = sqrt(p[0] * p[0] + p[2] * p[2]);
            u = (phi + M_PI) / (2 * M_PI);
            v = r;
        }

        inline Math::Vector<3> getCenter() const;

                double getRadius() const {
            return this->_radius;
        }

        void setRadius(double radius) {
            this->_radius = radius;
        }

    private:
        Math::Vector<3> _center;
        Math::Vector<3> _normal;
        double _radius;
};
