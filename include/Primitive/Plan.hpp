/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Plan
*/

#ifndef PLAN_HPP_
    #define PLAN_HPP_

    #include "APrimitive.hpp"
    #include "Color.hpp"
    #include "Error.hpp"
    #include "Material/Lambertian.hpp"
    #include "Texture/SolidColor.hpp"

/**
 * @class Plan
 * @brief Represents a plan primitive in a ray tracer.
 *
 * The Plan class inherits from the APrimitive class and represents a plan primitive in a ray tracer.
 * It defines the properties and behavior of a plan in the scene.
 */
class Plan : public APrimitive {
    public:

        class PlanError : public Error {
            public:
                PlanError(const std::string &message) : Error(message) {}
        };

        /**
         * @brief Default constructor.
         */
        Plan();

        /**
         * @brief Parameterized constructor.
         * @param axis The axis along which the plan is positioned.
         * @param position The position of the plan along the specified axis.
         * @param color The color of the plan (default: white).
         */
        Plan(const std::string& axis, double position, const Color& color = Color(255, 255, 255));

        /**
         * @brief Parameterized constructor.
         * @param axis The axis along which the plan is positioned.
         * @param position The position of the plan along the specified axis.
         * @param material The material of the plan.
         */
        Plan(const std::string& axis, double position, const std::shared_ptr<IMaterial>& material);

        /**
         * @brief Destructor.
         */
        ~Plan();

        /**
         * @brief Checks if a ray intersects with the plan.
         * @param ray The ray to check for intersection.
         * @param ray_t The interval of the ray to consider for intersection.
         * @param record The hit record to update if an intersection is found.
         * @return True if the ray intersects with the plan, false otherwise.
         */
        bool hit(const Ray &ray, const Interval& ray_t, HitRecord& record) const override;

        /**
         * @brief Gets the UV coordinates of a point on the plan.
         * @param p The point on the plan.
         * @param u The U coordinate of the point.
         * @param v The V coordinate of the point.
        */
        inline void getPlanUV(Math::Vector<3> p, double& u, double& v) const
        {
            if (this->_axis == "x") {
                u = p[1];
                v = p[2];
            } else if (this->_axis == "y") {
                u = p[0];
                v = p[2];
            } else if (this->_axis == "z") {
                u = p[0];
                v = p[1];
            }
        }
    private:
        std::string _axis; ///< The axis along which the plan is positioned. */
        double _value; ///< The position value of the plan along the specified axis. */
        std::shared_ptr<IMaterial> _material; ///< The material of the plan. */
};

#endif /* !PLAN_HPP_ */
