/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** AMaterial
*/

#pragma once

#include "raytracer.hpp"
#include "IMaterial.hpp"

/**
 * @class AMaterial
 * @brief Abstract base class for materials used in ray tracing.
 *
 * The AMaterial class provides a common interface for materials used in ray tracing.
 * It inherits from the IMaterial interface and defines a virtual function for scattering rays.
 * It also contains a protected member variable for the material's albedo color.
 */
class AMaterial : public IMaterial {
    public:
        /**
         * @brief Default destructor.
         */
        ~AMaterial() = default;

        /**
         * @brief Emit light from the material.
         * @param ray The incident ray.
         * @param record The hit record containing information about the intersection.
         * @param u The u texture coordinate.
         * @param v The v texture coordinate.
         * @param point The point of intersection.
         * @return The emitted color.
        */
        Color emitted(const Ray& ray, const HitRecord& record, double u, double v, const Math::Vector<3>& point) const override;

        /**
         * @brief Scatter a ray off the material's surface.
         * @param ray The incident ray.
         * @param hit The hit record containing information about the intersection.
         * @param attenuation The color attenuation of the scattered ray.
         * @param scattered The scattered ray.
         * @return True if the ray is scattered, false otherwise.
         */
        virtual bool scatter(const Ray& ray, const HitRecord& hit, Color& attenuation, Ray& scattered) const override;

        void typeSet(std::string type_)
        {
            _stringType = type_;
        }
        std::string typeGet(void)
        {
            return _stringType;
        }
        void hasTextureSet(void)
        {
            _isTexture = true;
            _isColor = !_isTexture;
        }
        void hasColorSet(void)
        {
            _isColor = true;
            _isTexture = !_isColor;
        }
        bool hasTextureGet(void)
        {
            return _isTexture;
        }
        bool hasColorGet(void)
        {
            return _isColor;
        }
   
        Type getType() const { return this->_type; }

        Color getAlbedo() const { return this->_albedo; }
        void setAlbedo(const Color &color) { this->_albedo = color; }
    protected:
        Color _albedo; /**< The albedo color of the material. */
        std::string _stringType;
        bool _isTexture;
        bool _isColor;
        Type _type; /**< The type of the material. */
};
