/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Cylindre
*/

#ifndef CYLINDRE_HPP_
    #define CYLINDRE_HPP_

    #include "APrimitive.hpp"
    #include "Disk.hpp"
    #include "Vector.hpp"
    #include "Plan.hpp"

/**
 * @class Cylindre
 * @brief Represents a cylinder primitive in a raytracer.
 *
 * The Cylindre class inherits from the APrimitive class and represents a cylinder primitive in a raytracer.
 * It defines the properties and behavior of a cylinder, such as its position, depth, and radius.
 */
class Cylindre : public APrimitive {
    using d64 = double;
    public:
        /**
         * @brief Default constructor for Cylindre.
         */
        Cylindre();

        /**
         * @brief Constructor for Cylindre.
         * @param position The position of the cylinder.
         * @param depth The depth of the cylinder.
         * @param radius The radius of the cylinder.
         */
        Cylindre(const Math::Vector<3>& _center, double depth, double radius, std::shared_ptr<IMaterial> material = nullptr);

        /**
         * @brief Destructor for Cylindre.
         */
        ~Cylindre();

        void setRadius(d64 radius) noexcept
        {
            _radius = radius;
        }
        void setDepth(d64 depth) noexcept
        {
            _depth = depth;
        }
        void setMaterial(std::shared_ptr<IMaterial> material) noexcept
        {
            _material = material;
        }
        [[nodiscard]] d64 getRadius(void) const noexcept
        {
            return _radius;
        }
        [[nodiscard]] d64 getDepth(void) const noexcept
        {
            return _depth;
        }
        [[nodiscard]] std::shared_ptr<IMaterial> getMaterial(void) const noexcept
        {
            return _material;
        }
        /**
         * @brief Checks if a ray intersects with the cylinder.
         * @param ray The ray to check for intersection.
         * @param ray_t The interval of the ray to check for intersection.
         * @param record The hit record to store the intersection information.
         * @return True if the ray intersects with the cylinder, false otherwise.
         */
        bool hit(const Ray &ray, const Interval &ray_t, HitRecord &record) const override;

        void setCenter(Math::Vector<3> center) { this->_center = center; }
        Math::Vector<3> getCenter() const { return this->_center; }
    protected:
    private:
        double _depth; /**< The depth of the cylinder. */
        double _radius; /**< The radius of the cylinder. */
        Math::Vector<3> _center; /**< The position of the cylinder. */
        Disk _topDisk;
        Disk _bottomDisk;
};

#endif /* !CYLINDRE_HPP_ */
