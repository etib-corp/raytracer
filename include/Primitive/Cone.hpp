/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Cone
*/

#pragma once

#include "raytracer.hpp"

#include "Vector.hpp"
#include "Ray.hpp"
#include "APrimitive.hpp"
#include "Rectangle.hpp"
#include "Disk.hpp"


#define SQUARE(x) ((x) * (x))

class Cone : public APrimitive {
    public:
        /**
         * @brief Default constructor.
         */
        Cone();

        /**
         * @brief Parameterized constructor.
         * @param baseCenter The base center of the Cone.
         * @param top The top of the Cone.
         * @param radius The radius of the Cone.
         * @param naterial The material to be set on the Cone.
         */
        Cone(const Math::Vector<3>& baseCenter, double height, double radius, std::shared_ptr<IMaterial> material);

        /**
         * @brief Default destructor.
         */
        ~Cone() = default;

        /**
         * @brief Checks for ray-Cone intersection.
         * @param ray The ray to check intersection with.
         * @param ray_t The interval of the ray to consider.
         * @param record The hit record to update if intersection occurs.
         * @return True if intersection occurs, false otherwise.
         */
        bool hit(const Ray &ray, const Interval& ray_t, HitRecord& record) const override;

        static inline void getConeUV(const Math::Vector<3>& p, double& u, double& v)
        {
            double phi = atan2(p[0], p[2]);
            double r = sqrt(p[0] * p[0] + p[2] * p[2]);
            u = (phi + M_PI) / (2 * M_PI);
            v = p[1];
        }

        double getRadius() const {
            return this->_radius;
        }

        double getHeight() const {
            return this->_height;
        }

        void setRadius(double radius) {
            this->_radius = radius;
        }

        void setHeight(double depth) {
            this->_height = depth;
        }

        void setBaseCenter(Math::Vector<3> center) { this->_baseCenter = center; }
        Math::Vector<3> getBaseCenter() const { return this->_baseCenter; }


    private:
        double _height; // Height of the Cone
        Math::Vector<3> _baseCenter; ///< The base center of the Cone.
        double _radius; ///< The radius of the Cone.
        double _angle; ///< The angle of the Cone
        Disk _base;
};

