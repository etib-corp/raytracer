/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** LMaterial
*/

#ifndef LMATERIAL_HPP_
#define LMATERIAL_HPP_

#include <bits/stdc++.h>
#include "Vector.hpp"

/**
 * @class LRefractive
 * @brief Represents a refractive material.
 *
 * The LRefractive class stores information about a refractive material, including its name and refractive index.
 */
class LRefractive
{
    using d64 = double;
public:
    /**
     * @brief Constructs a PRefractive object with the given name and refractive index.
     * @param name The name of the refractive material.
     * @param refractiveIndex The refractive index of the material.
     */
    LRefractive(std::string name, d64 refractiveIndex) : _refractiveIndex(refractiveIndex)
    {
        _name = name;
    }

    /**
     * @brief Default constructor for PRefractive.
     */
    LRefractive() = default;

    /**
     * @brief Prints the refractive material information.
     */
    void print() const
    {
        std::cout << "\tRefractiveIndex: " << _name << _refractiveIndex << std::endl;
        std::cout << std::endl;
    }

    /**
     * @brief Retrieves the refractive index of the material.
     * @return The refractive index.
     */
    [[nodiscard]] d64 refractiveIndexGet(void) const noexcept { return _refractiveIndex; }

private:
    std::string _name; ///< The name of the refractive material.
    d64 _refractiveIndex; ///< The refractive index of the material.
};

/**
 * @class LColor
 * @brief Represents a color with a name and RGB values.
 */
class LColor
{
    public:
        /**
         * @brief Constructs a PColor object with the given name and RGB values.
         * @param name The name of the color.
         * @param rgb The RGB values of the color.
         */
        LColor(std::string name, Math::Vector<3> rgb) : _rgb(rgb)
        {
            _name = name;
        }

        /**
         * @brief Prints the color name and RGB values.
         */
        void print() const
        {
            std::cout << "\tColor: " << _name << _rgb << std::endl;
            std::cout << std::endl;
        }

        /**
         * @brief Returns the RGB values of the color.
         * @return The RGB values of the color.
         */
        Math::Vector<3> rgbGet(void) { return _rgb; }

    private:
        std::string _name; ///< The name of the color.
        Math::Vector<3> _rgb; ///< The RGB values of the color.
};

/**
 * @brief The PTexture class represents a texture used in ray tracing.
 */
class LTexture
{
public:
    /**
     * @brief Constructs a PTexture object with the given name.
     * @param name The name of the texture.
     */
    LTexture(const std::string& name)
    {
        _name = name;
    }

    /**
     * @brief Prints information about the texture.
     */
    void print() const
    {
        std::cout << "\tTexture: " << _name << std::endl;
        std::cout << "\t\tscale: " << _scale << std::endl;
        for (const auto& color : _colors)
            std::cout << "\t\tColor:" << color << std::endl;
        std::cout << std::endl;
    }

    /**
     * @brief Sets the scale of the texture.
     * @param scale The scale value to set.
     */
    void scaleSet(const double& scale) { _scale = scale; }

    /**
     * @brief Gets the scale of the texture.
     * @return The scale value.
     */
    [[nodiscard]] inline double scaleGet() { return _scale; }

    /**
     * @brief Sets the colors of the texture.
     * @param color The color to add to the texture.
     */
    void colorsSet(Math::Vector<3> color) { _colors.push_back(color); }

    /**
     * @brief Gets the colors of the texture.
     * @return A vector of colors.
     */
    [[nodiscard]] std::vector<Math::Vector<3>> colorsGet(void) { return _colors; };

private:
    double _scale;                          ///< The scale of the texture.
    std::string _name;                      ///< The name of the texture.
    std::vector<Math::Vector<3>> _colors;    ///< The colors of the texture.
};

/**
 * @class LMaterial
 * @brief Represents a material in the raytracer.
 *
 * The PMaterial class stores information about a material, including its name, colors, textures, and refractive indices.
 * It provides methods to add and retrieve colors, textures, and refractive indices, as well as to set and get flags indicating whether the material has color, texture, or refraction.
 * The class also provides a method to print the material's colors and textures.
 */
class LMaterial
{
public:
    /**
     * @brief Default constructor for the PMaterial class.
     *
     * This constructor initializes the PMaterial object with default values.
     * The `_isColor`, `_isRefractive`, and `_isTexture` member variables are set to `false`.
     */
    LMaterial() = default;

    /**
     * @brief Adds a color to the list of colors.
     *
     * @param color The color to be added.
     */
    void addColor(const LColor& color)
    {
        _colors.push_back(color);
    }

    /**
     * @brief Gets the list of colors.
     *
     * @return The list of colors.
     */
    std::vector<LColor> colorGet(void) const { return _colors; }

    /**
     * @brief Prints the material.
     *
     * This method prints the colors and textures of the material.
     */
    void print() const
    {
        for (const auto& color : _colors)
            color.print();
    }

    /**
     * @brief Sets the name of the material.
     *
     * @param name The name of the material.
     */
    void nameSet(const std::string& name) { _name = name; }

    /**
     * @brief Gets the name of the material.
     *
     * @return The name of the material.
     */
    std::string nameGet(void) const { return _name; }

    /**
     * @brief Sets whether the material has a color.
     *
     * @param hasColor Whether the material has a color.
     */
    void isDirectionalSet(const bool& hasColor) noexcept
    {
        _isDirectional = true;
        _isDiffuse = false;
    }

private:
    std::string _name;                      // The name of the material
    std::vector<LColor> _colors;              // The list of colors
    bool _isDirectional = false;                         // Whether the material has a texture
    bool _isDiffuse = false;                           // Whether the material has a color
};

#endif /* !LMATERIAL_HPP_ */
