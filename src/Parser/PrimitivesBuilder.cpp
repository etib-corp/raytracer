/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** PrimitivesBuilder
*/

#include "Parser/PrimitivesBuilder.hpp"
#include "Texture/Checker.hpp"
#include "Texture/SolidColor.hpp"
#include "Material/Metal.hpp"
#include "Material/Lambertian.hpp"
#include "Material/Dielectric.hpp"
#include "Parser/PMaterial.hpp"
#include "Parser/LightBuilder.hpp"

PrimitivesBuilder& PrimitivesBuilder::addSphere(const Position& position, double radius, const Color& color, const Rotation& rotation, const Translation& translation, const PMaterial& material)
{
    Sphere sphere;
    sphere.setCenter(Math::Vector<3>({position.x, position.y, position.z}));
    sphere.setRadius(radius);

    if (material.isColorGet())
    {
        if (material.nameGet() == "Metal")
        {
            PColor l_color = material.colorGet().front();
            Math::Vector<3> l_vec = l_color.rgbGet();
            sphere.setMaterial(std::make_shared<Metal>(Color(l_vec[0], l_vec[1], l_vec[2]), 0.0));
        }
        if (material.nameGet() == "Lambertian")
        {
            PColor l_color = material.colorGet().front();
            Math::Vector<3> l_vec = l_color.rgbGet();
            sphere.setMaterial(std::make_shared<Lambertian>(Color(l_vec[0], l_vec[1], l_vec[2], 1.0)));
        }
    }
    if (material.istextureGet())
    {
        if (material.nameGet() == "Lambertian")
        {
            PTexture l_texture = material.textureGet().front();
            Math::Vector firstColor =  l_texture.colorsGet().at(0);
            Math::Vector secondColor =  l_texture.colorsGet().at(1);

            auto lChecker = std::make_shared<Checker>(l_texture.scaleGet(), Color(firstColor[0], firstColor[1], firstColor[2]), Color(secondColor[0], secondColor[1], secondColor[2]));
            sphere.setMaterial(std::make_shared<Lambertian>(lChecker));
        }
    }
    if (material.isRefractiveGet())
    {
        if (material.nameGet() == "Dielectric")
        {
            PRefractive l_refractive = material.refractiveGet().front();
            auto material1 = std::make_shared<Dielectric>(l_refractive.refractiveIndexGet());
            sphere.setMaterial(material1);
        }
    }
    _objList.add(std::make_shared<Sphere>(sphere));
    return *this;
}

PrimitivesBuilder& PrimitivesBuilder::addCylindre(const Position& position, const d64& radius, const d64& depth, const PMaterial& material)
{
    std::shared_ptr<IMaterial> material_;

    if (material.isColorGet())
    {
        if (material.nameGet() == "Metal")
        {
            PColor l_color = material.colorGet().front();
            Math::Vector<3> l_vec = l_color.rgbGet();
            material_ = std::make_shared<Metal>(Color(l_vec[0], l_vec[1], l_vec[2]), 0.0);
        }
        if (material.nameGet() == "Lambertian")
        {
            PColor l_color = material.colorGet().front();
            Math::Vector<3> l_vec = l_color.rgbGet();
            material_ = std::make_shared<Lambertian>(Color(l_vec[0], l_vec[1], l_vec[2], 1.0));
        }
    }
    if (material.istextureGet())
    {
        if (material.nameGet() == "Lambertian")
        {
            PTexture l_texture = material.textureGet().front();
            Math::Vector firstColor =  l_texture.colorsGet().at(0);
            Math::Vector secondColor =  l_texture.colorsGet().at(1);
            auto lChecker = std::make_shared<Checker>(l_texture.scaleGet(), Color(firstColor[0], firstColor[1], firstColor[2]), Color(secondColor[0], secondColor[1], secondColor[2]));

            material_ = std::make_shared<Lambertian>(lChecker);
        }
    }
    if (material.isRefractiveGet())
    {
        if (material.nameGet() == "Dielectric")
        {
            PRefractive l_refractive = material.refractiveGet().front();
            material_ = std::make_shared<Dielectric>(l_refractive.refractiveIndexGet());
        }
    }
    _objList.add(std::make_shared<Cylindre>(Math::Vector<3>({position.x, position.y, position.z}), depth, radius, material_));
    return *this;
}

PrimitivesBuilder& PrimitivesBuilder::addCone(const Position& position, const d64& radius, const d64& height, const PMaterial& material)
{
    std::shared_ptr<IMaterial> material_;

    if (material.isColorGet())
    {
        if (material.nameGet() == "Metal")
        {
            PColor l_color = material.colorGet().front();
            Math::Vector<3> l_vec = l_color.rgbGet();
            material_ = std::make_shared<Metal>(Color(l_vec[0], l_vec[1], l_vec[2]), 0.0);
        }
        if (material.nameGet() == "Lambertian")
        {
            PColor l_color = material.colorGet().front();
            Math::Vector<3> l_vec = l_color.rgbGet();
            material_ = std::make_shared<Lambertian>(Color(l_vec[0], l_vec[1], l_vec[2], 1.0));
        }
    }
    if (material.istextureGet())
    {
        if (material.nameGet() == "Lambertian")
        {
            PTexture l_texture = material.textureGet().front();
            Math::Vector firstColor =  l_texture.colorsGet().at(0);
            Math::Vector secondColor =  l_texture.colorsGet().at(1);
            auto lChecker = std::make_shared<Checker>(l_texture.scaleGet(), Color(firstColor[0], firstColor[1], firstColor[2]), Color(secondColor[0], secondColor[1], secondColor[2]));

            material_ = std::make_shared<Lambertian>(lChecker);
        }
    }
    if (material.isRefractiveGet())
    {
        if (material.nameGet() == "Dielectric")
        {
            PRefractive l_refractive = material.refractiveGet().front();
            material_ = std::make_shared<Dielectric>(l_refractive.refractiveIndexGet());
        }
    }
    _objList.add(std::make_shared<Cone>(Math::Vector<3>({position.x, position.y, position.z}), height, radius, material_));
    return *this;
}

PrimitivesBuilder& PrimitivesBuilder::addDisk(const Position& center, const Position& normal, const d64& radius, const PMaterial& material)
{
    std::shared_ptr<IMaterial> material_;

    if (material.isColorGet())
    {
        if (material.nameGet() == "Metal")
        {
            PColor l_color = material.colorGet().front();
            Math::Vector<3> l_vec = l_color.rgbGet();
            material_ = std::make_shared<Metal>(Color(l_vec[0], l_vec[1], l_vec[2]), 0.0);
        }
        if (material.nameGet() == "Lambertian")
        {
            PColor l_color = material.colorGet().front();
            Math::Vector<3> l_vec = l_color.rgbGet();
            material_ = std::make_shared<Lambertian>(Color(l_vec[0], l_vec[1], l_vec[2], 1.0));
        }
    }
    if (material.istextureGet())
    {
        if (material.nameGet() == "Lambertian")
        {
            PTexture l_texture = material.textureGet().front();
            Math::Vector firstColor =  l_texture.colorsGet().at(0);
            Math::Vector secondColor =  l_texture.colorsGet().at(1);
            auto lChecker = std::make_shared<Checker>(l_texture.scaleGet(), Color(firstColor[0], firstColor[1], firstColor[2]), Color(secondColor[0], secondColor[1], secondColor[2]));

            material_ = std::make_shared<Lambertian>(lChecker);
        }
    }
    if (material.isRefractiveGet())
    {
        if (material.nameGet() == "Dielectric")
        {
            PRefractive l_refractive = material.refractiveGet().front();
            material_ = std::make_shared<Dielectric>(l_refractive.refractiveIndexGet());
        }
    }
    _objList.add(std::make_shared<Disk>(Math::Vector<3>({center.x, center.y, center.z}), Math::Vector<3>({normal.x, normal.y, normal.z}), radius, material_));
    return *this;
}

PrimitivesBuilder& PrimitivesBuilder::addPlane(std::string axis, d64 position, const Color& color)
{
    // Plan plane;

    std::cout << position << std::endl;

    // plane.setAxis(axis);
    // plane.setPosition(static_cast<double>(position));
    // plane.setColor(color);
    // _planes.push_back(std::move(plane));
    _objList.add(std::make_shared<Plan>(axis, position, color));
    return *this;
}

PrimitivesBuilder& PrimitivesBuilder::addLight(const Position& center, const Position& normal, const d64& radius, const PMaterial& material)
{
    std::shared_ptr<IMaterial> material_;

    if (material.nameGet() == "Directionnal")
    {
        PColor l_color = material.colorGet().front();
        Math::Vector<3> l_vec = l_color.rgbGet();
        material_ = std::make_shared<Directionnal>(Color(l_vec[0], l_vec[1], l_vec[2], 1.0));
    }
    if (material.nameGet() == "Diffuse")
    {
        PColor l_color = material.colorGet().front();
        Math::Vector<3> l_vec = l_color.rgbGet();
        material_ = std::make_shared<Diffuse>(Color(l_vec[0], l_vec[1], l_vec[2], 1.0));
    }

    _objList.add(std::make_shared<Disk>(Math::Vector<3>({center.x, center.y, center.z}), Math::Vector<3>({normal.x, normal.y, normal.z}), radius, material_));
    return *this;
}

void PrimitivesBuilder::print(void) const
{
    std::cout << "Primitives:\n";
    for (const auto& _sphere : _spheres) {
            std::cout << _sphere.getPosition() << std::endl;
            std::cout << _sphere.getCenter() << std::endl;
            std::cout << _sphere.getRadius() << std::endl;
    }
    std::cout << std::endl;
}
