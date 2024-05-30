/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** CFGParser
*/

#ifndef CFGPARSER_HPP_
#define CFGPARSER_HPP_

#include <iostream>
#include <cstdint>
#include <fstream>
#include <string>
#include <libconfig.h++>
#include "Color.hpp"
#include "Position.hpp"
#include "Rotation.hpp"
#include "Translation.hpp"
#include "Point.hpp"
#include "ATexture.hpp"
#include "Vector.hpp"
#include "PMaterial.hpp"
#include "LMaterial.hpp"

using namespace libconfig;


/**
 * @class CFGParser
 * @brief A class for parsing configuration files and extracting camera and primitive information.
 *
 * The CFGParser class is responsible for reading a configuration file and extracting various camera and primitive properties.
 * It provides methods to retrieve camera resolution, position, rotation, field of view, and other camera settings.
 * It also provides methods to retrieve information about spheres, cylinders, lights, and other primitives defined in the configuration file.
 */
class CFGParser : public Color, public Position, public Rotation, public Translation, public Point {
    using i32 = int32_t;
    using i64 = int64_t;
    using ui32 = uint32_t;
    using d64 = double;

private:
    /**
     * @brief Represents the configuration settings for the parser.
     */
    Config _cfg;

    /**
     * @brief Checks if a file is valid by attempting to open it and checking if it is empty.
     *
     * @param filename The name of the file to check.
     * @return true if the file is valid (empty), false otherwise.
     */
    [[nodiscard]] bool isValidFile(const std::string& filename)
    {
        std::ifstream file(filename);
        return (file.peek() == std::ifstream::traits_type::eof());
    }

protected:
public:
    /**
     * @brief Constructs a CFGParser object.
     *
     * This constructor reads the contents of the specified file and checks if it is a valid file.
     * If the file is empty, it throws an exception and prints an error message to the standard error stream.
     *
     * @param filename The name of the file to be parsed.
     */
    CFGParser(const std::string &filename)
    {
        _cfg.readFile(filename);
        if (isValidFile(filename))
            throw "Empty file";
    }

    /**
     * @brief Retrieves the camera resolution from the configuration file.
     *
     * @return A pair of doubles representing the width and height of the camera resolution.
     */
    [[nodiscard]] std::pair<d64, d64> cameraResolutionGet(void)
    {
        const Setting& root = _cfg.getRoot();
        const Setting& camera = _cfg.lookup("camera");
        const Setting& resolution = camera.lookup("resolution");
        d64 width = 0, height = 0;

        resolution.lookupValue("width", width);
        resolution.lookupValue("height", height);
        return std::make_pair(width, height);
    }

    /**
     * @brief Retrieves the camera position from the configuration file.
     *
     * @return A tuple of doubles representing the x, y, and z coordinates of the camera position.
     */
    [[nodiscard]] std::tuple<d64, d64, d64> cameraPositionGet(void)
    {
        const Setting& root = _cfg.getRoot();
        const Setting& camera = _cfg.lookup("camera");
        const Setting& resolution = camera.lookup("position");
        d64 x = 0, y = 0, z = 0;

        resolution.lookupValue("x", x);
        resolution.lookupValue("y", y);
        resolution.lookupValue("z", z);
        return std::make_tuple(x, y, z);
    }

    /**
     * @brief Retrieves the camera position at from the configuration file.
     *
     * @return A tuple of doubles representing the x, y, and z coordinates of the camera position at.
     */
    [[nodiscard]] std::tuple<d64, d64, d64> cameraPositionAtGet(void) const
    {
        d64 x = 0, y = 0, z = 0;
        const Setting& root = _cfg.getRoot();
        const Setting& camera = _cfg.lookup("camera");
        if (!camera.exists("positionAt"))
            return std::make_tuple(0, 0, 0);
        const Setting& resolution = camera.lookup("positionAt");

        resolution.lookupValue("x", x);
        resolution.lookupValue("y", y);
        resolution.lookupValue("z", z);
        return std::make_tuple(x, y, z);
    }

    /**
     * @brief Retrieves the camera rotation from the configuration file.
     *
     * @return A tuple of integers representing the x, y, and z rotation angles of the camera.
     */
    [[nodiscard]] std::tuple<i32, i32, i32> cameraRotationGet(void)
    {
        const Setting& root = _cfg.getRoot();
        const Setting& camera = _cfg.lookup("camera");
        const Setting& resolution = camera.lookup("rotation");
        i32 x = 0, y = 0, z = 0;

        resolution.lookupValue("x", x);
        resolution.lookupValue("y", y);
        resolution.lookupValue("z", z);
        return std::make_tuple(x, y, z);
    }

    /**
     * @brief Retrieves the field of view from the configuration file.
     *
     * @return The field of view value as a double.
     */
    [[nodiscard]] d64 fieldOfViewGet(void)
    {
        const Setting& root = _cfg.getRoot();
        const Setting& camera = _cfg.lookup("camera");
        d64 x = 0;

        camera.lookupValue("fieldOfView", x);
        return x;
    }

    /**
     * @brief Retrieves the maximum depth of the camera from the configuration file.
     *
     * @return The maximum depth value as an integer.
     */
    [[nodiscard]] i32 cameraMaxDepthGet(void)
    {
        const Setting& root = _cfg.getRoot();
        const Setting& camera = _cfg.lookup("camera");
        i32 x = 50;

        camera.lookupValue("maxDepth", x);
        return x;
    }

    /**
     * @brief Retrieves the sample per pixel value from the configuration file.
     *
     * @return The sample per pixel value as an integer.
     */
    [[nodiscard]] i32 cameraSamplePerPixelGet(void)
    {
        i32 samplePerPixel = 32;
        const Setting& root = _cfg.getRoot();
        const Setting& camera = _cfg.lookup("camera");

        camera.lookupValue("samplePerPixel", samplePerPixel);
        return samplePerPixel;
    }

    /**
     * @brief Retrieves the light value from the configuration file.
     *
     * @return true if the light is enabled, false otherwise.
     */
    [[nodiscard]] bool cameraLightGet(void)
    {
        bool isLight = true;
        const Setting& root = _cfg.getRoot();
        const Setting& camera = _cfg.lookup("camera");

        camera.lookupValue("light", isLight);
        return isLight;
    }

    /**
     * @brief Retrieves the background color of the camera from the configuration file.
     *
     * @return The background color as a Color object.
     */
    [[nodiscard]] Color cameraBackgroundColorGet(void)
    {
        d64 r = 0, g = 0, b = 0;
        const Setting& root = _cfg.getRoot();
        const Setting& camera = _cfg.lookup("camera");
        if (!camera.exists("backgroundColor"))
            return {0, 0, 0};
        const Setting& resolution = camera.lookup("backgroundColor");

        resolution.lookupValue("r", r);
        resolution.lookupValue("g", g);
        resolution.lookupValue("b", b);
        return {r, g, b};
    }

    /**
     * @brief Retrieves the root setting of the configuration file.
     *
     * @return The root setting as a const reference.
     */
    [[nodiscard]] const Setting& getRoot(void)
    {
        const Setting& root = _cfg.getRoot();
        return root;
    }

    /**
     * @brief Retrieves the root setting of the plane section in the configuration file.
     *
     * @return The root setting of the plane section as a const reference.
     */
    [[nodiscard]] const Setting& planeGetRoot(void)
    {
        const Setting& root = _cfg.getRoot();
        const Setting& primitives = root["primitives"];
        const Setting& planes = primitives["planes"];
        return root;
    }

    /*      Sphere section   */

    /**
     * @brief Retrieves the number of spheres in the configuration file.
     *
     * @return The number of spheres as an unsigned integer.
     */
    [[nodiscard]] ui32 nbSphereGet(void)
    {
        return getRoot()["primitives"]["spheres"].getLength();
    }

    /**
     * @brief Retrieves the number of cylinders in the configuration file.
     *
     * @return The number of cylinders as an unsigned integer.
     */
    [[nodiscard]] ui32 nbCylindreGet(void)
    {
        return getRoot()["primitives"]["cylindres"].getLength();
    }

    [[nodiscard]] ui32 nbLightDiffuseGet(void)
    {
        return getRoot()["lights"]["diffuse"].getLength();
    }

    [[nodiscard]] ui32 nbLightDirectionalGet(void)
    {
        return getRoot()["lights"]["directional"].getLength();
    }

    /**
     * @brief Retrieves the number of cones in the configuration file.
     *
     * @return The number of cones as an unsigned integer.
     */
    [[nodiscard]] ui32 nbConeGet(void)
    {
        return getRoot()["primitives"]["cones"].getLength();
    }

    /**
     * @brief Retrieves the number of cones in the configuration file.
     *
     * @return The number of cones as an unsigned integer.
     */
    [[nodiscard]] ui32 nbDiskGet(void)
    {
        return getRoot()["primitives"]["disks"].getLength();
    }

    /**
     * @brief Retrieves the position of a specific cylinder from the configuration file.
     *
     * @param index The index of the cylinder.
     * @return The position of the cylinder as a Position object.
     */
    [[nodiscard]] Position withCylindrePositionGet(const ui32 index)
    {
        d64 x = 0, y = 0, z = 0;
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        const Setting& cylindres = primitives["cylindres"];
        const Setting& cylindre = cylindres[index];

        cylindre.lookupValue("x", x);
        cylindre.lookupValue("y", y);
        cylindre.lookupValue("z", z);
        return {x, y, z};
    }

    /**
     * @brief Retrieves the radius of a specific cylinder from the configuration file.
     *
     * @param index The index of the cylinder.
     * @return The radius of the cylinder as a double.
     */
    [[nodiscard]] d64 withCylindreRadiusGet(const ui32 index)
    {
        d64 radius = 0;
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        const Setting& cylindres = primitives["cylindres"];
        const Setting& cylindre = cylindres[index];

        cylindre.lookupValue("r", radius);
        return radius;
    }

    /**
     * @brief Retrieves the depth of a specific cylinder from the configuration file.
     *
     * @param index The index of the cylinder.
     * @return The depth of the cylinder as a double.
     */
    [[nodiscard]] d64 withCylindreDepthGet(const ui32 index)
    {
        d64 depth = 0;
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        const Setting& cylindres = primitives["cylindres"];
        const Setting& cylindre = cylindres[index];

        cylindre.lookupValue("depth", depth);
        return depth;
    }

    /**
     * @brief Retrieves the material of a specific cylinder from the configuration file.
     *
     * @param index The index of the cylinder.
     * @return The material of the cylinder as a PMaterial object.
     */
    [[nodiscard]] PMaterial withCylindreMaterialGet(const ui32 index)
    {
        std::string sType;
        PMaterial pcylindre;
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        const Setting& cylindres = primitives["cylindres"];
        const Setting& cylindre = cylindres[index];
        const Setting& material = cylindre.lookup("material");

        material.lookupValue("type", sType);
        pcylindre.nameSet(sType);

        if (material.exists("textures"))
        {
            PTexture ptexture(sType);
            d64 scale = 0.0;
            const Setting& textures = material.lookup("textures");

            pcylindre.istextureSet(true);
            textures.lookupValue("scale", scale);
            ptexture.scaleSet(scale);

            const Setting& colors = textures.lookup("colors");
            for (ui32 i = 0; i != colors.getLength(); ++i) {
                d64 rgb[3] = {0};
                colors[i].lookupValue("r", rgb[0]);
                colors[i].lookupValue("g", rgb[1]);
                colors[i].lookupValue("b", rgb[2]);
                ptexture.colorsSet((Math::Vector<3>({rgb[0], rgb[1], rgb[2]})));
            }
            pcylindre.addTexture(ptexture);
        }
        if (material.exists("color"))
        {
            d64 rgb[3] = {0.0};
            const Setting& color = material.lookup("color");
            pcylindre.isColorSet(true);
            color.lookupValue("r", rgb[0]);
            color.lookupValue("g", rgb[1]);
            color.lookupValue("b", rgb[2]);
            pcylindre.addColor(PColor(sType, Math::Vector<3>({rgb[0], rgb[1], rgb[2]})));
        }
        if (material.exists("refractive"))
        {
            pcylindre.isRefractiveSet(true);
            d64 refractive_index = 0.0;
            const Setting& color = material.lookup("refractive");
            color.lookupValue("refractive_index", refractive_index);
            pcylindre.addRefractive(PRefractive(sType, refractive_index));
        }
        return std::move(pcylindre);
    }

    /**
     * @brief Get the number of point lights in the configuration.
     *
     * @return The number of point lights.
     */
    [[nodiscard]] ui32 nbLightsGet(void)
    {
        return getRoot()["lights"]["point"].getLength();
    }

    /**
     * @brief Retrieves the position of a sphere at the specified index.
     *
     * This function retrieves the x, y, and z coordinates of a sphere at the specified index
     * from the configuration file. It uses the CFGParser object to access the configuration
     * settings and lookup the values for the sphere's position.
     *
     * @param index The index of the sphere.
     * @return The position of the sphere as a Position object.
     */
    [[nodiscard]] Position withSpherePositionGet(const ui32 index)
    {
        d64 x = 0, y = 0, z = 0;
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        const Setting& spheres = primitives["spheres"];
        const Setting& sphere = spheres[index];

        sphere.lookupValue("x", x);
        sphere.lookupValue("y", y);
        sphere.lookupValue("z", z);
        return {x, y, z};
    }
    /**
     * @brief Retrieves the radius of a sphere at the specified index.
     *
     * This function retrieves the radius of a sphere at the specified index from the configuration file.
     * The radius can be either an integer or a floating-point value.
     *
     * @param index The index of the sphere.
     * @return The radius of the sphere at the specified index.
     *         If the radius is a floating-point value, it is returned as a double.
     *         If the radius is an integer value, it is returned as an integer.
     *         If the sphere or the radius is not found, 0 is returned.
     */
    [[nodiscard]] i32 withSphereRadiusGet(const ui32 index)
    {
        i32 iradius = 0;
        d64 dradius = 0;
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        const Setting& spheres = primitives["spheres"];
        const Setting& sphere = spheres[index];

        if (sphere["r"].getType() == libconfig::Setting::TypeFloat)
        {
            sphere.lookupValue("r", dradius);
            return dradius;
        }
        if (sphere["r"].getType() == libconfig::Setting::TypeInt)
        {
            sphere.lookupValue("r", iradius);
            return iradius;
        }
        return 0;
    }
    /**
     * @brief Retrieves the color of a sphere at the specified index.
     *
     * @param index The index of the sphere.
     * @return The color of the sphere as a Color object.
     */
    [[nodiscard]] Color withSphereColorGet(const ui32 index)
    {
        i32 rgb[3] = {0};
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        const Setting& spheres = primitives["spheres"];
        const Setting& sphere = spheres[index];
        if (!sphere.exists("color"))
            return {0, 0, 0};
        const Setting& color = sphere.lookup("color");

        color.lookupValue("r", rgb[0]);
        color.lookupValue("g", rgb[1]);
        color.lookupValue("b", rgb[2]);
        return {static_cast<d64>(rgb[0]), static_cast<d64>(rgb[1]), static_cast<d64>(rgb[2])};
    }
    /**
     * @brief Retrieves the rotation values for a sphere at the specified index.
     *
     * @param index The index of the sphere.
     * @return The rotation values as a `Rotation` object.
     *         If the sphere does not have a rotation, the default rotation {0, 0, 0} is returned.
     */
    [[nodiscard]] Rotation withSphereRotationGet(const ui32 index)
    {
        i32 lRotation[3] = {0};
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        const Setting& spheres = primitives["spheres"];
        const Setting& sphere = spheres[index];
        if (!sphere.exists("rotation"))
            return {0, 0, 0};
        const Setting& rotation = sphere.lookup("rotation");

        rotation.lookupValue("x", lRotation[0]);
        rotation.lookupValue("y", lRotation[1]);
        rotation.lookupValue("z", lRotation[2]);

        return {lRotation[0], lRotation[1], lRotation[2]};
    }
    /**
     * @brief Retrieves the translation values for a sphere at the specified index.
     *
     * This function returns a Translation object that contains the x, y, and z translation values
     * for the sphere at the given index. If the sphere does not have a translation defined,
     * a Translation object with all values set to 0 is returned.
     *
     * @param index The index of the sphere.
     * @return The Translation object containing the x, y, and z translation values.
     */
    [[nodiscard]] Translation withSphereTranslationGet(const ui32 index)
    {
        i32 lTranslation[3] = {0};
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        const Setting& spheres = primitives["spheres"];
        const Setting& sphere = spheres[index];
        if (!sphere.exists("translation"))
            return {0, 0, 0};
        const Setting& rotation = sphere.lookup("translation");

        rotation.lookupValue("x", lTranslation[0]);
        rotation.lookupValue("y", lTranslation[1]);
        rotation.lookupValue("z", lTranslation[2]);

        return {lTranslation[0], lTranslation[1], lTranslation[2]};
    }
    /**
     * @brief Retrieves the material information for a sphere at the specified index.
     *
     * @param index The index of the sphere.
     * @return The material information for the sphere.
     */
    [[nodiscard]] PMaterial withSphereMaterialGet(const ui32 index)
    {
        std::string sType;
        PMaterial pshere;
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        const Setting& spheres = primitives["spheres"];
        const Setting& sphere = spheres[index];
        const Setting& material = sphere.lookup("material");

        material.lookupValue("type", sType);
        pshere.nameSet(sType);


        if (material.exists("textures"))
        {
            PTexture ptexture(sType);
            d64 scale = 0.0;
            const Setting& textures = material.lookup("textures");

            pshere.istextureSet(true);
            textures.lookupValue("scale", scale);
            ptexture.scaleSet(scale);

            const Setting& colors = textures.lookup("colors");
            for (ui32 i = 0; i != colors.getLength(); ++i) {
                d64 rgb[3] = {0};
                colors[i].lookupValue("r", rgb[0]);
                colors[i].lookupValue("g", rgb[1]);
                colors[i].lookupValue("b", rgb[2]);
                ptexture.colorsSet((Math::Vector<3>({rgb[0], rgb[1], rgb[2]})));
            }
            pshere.addTexture(ptexture);
        }
        if (material.exists("color"))
        {
            d64 rgb[3] = {0.0};
            const Setting& color = material.lookup("color");
            pshere.isColorSet(true);
            color.lookupValue("r", rgb[0]);
            color.lookupValue("g", rgb[1]);
            color.lookupValue("b", rgb[2]);
            pshere.addColor(PColor(sType, Math::Vector<3>({rgb[0], rgb[1], rgb[2]})));
        }
        if (material.exists("refractive"))
        {
            pshere.isRefractiveSet(true);
            d64 refractive_index = 0.0;
            const Setting& color = material.lookup("refractive");
            color.lookupValue("refractive_index", refractive_index);
            pshere.addRefractive(PRefractive(sType, refractive_index));
        }
        return std::move(pshere);
    }

        /*      Plane section   */

    /**
     * @brief Retrieves the axis of a plane at the specified index.
     *
     * @param index The index of the plane.
     * @return The axis of the plane as a character.
     */
    [[nodiscard]] std::string planeAxisGet(const ui32 index)
    {
        std::string c_axis;
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        if (!primitives.exists("planes"))
            return 0;
        const Setting& planes = primitives["planes"];
        const Setting& plane = planes[index];

        plane.lookupValue("axis", c_axis);

        return c_axis;
    }
    /**
     * Retrieves the position of a plane at the specified index.
     *
     * @param index The index of the plane.
     * @return The position of the plane.
     */
    [[nodiscard]] d64 planePositionGet(const ui32 index)
    {
        d64 l_position = 0;
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        if (!primitives.exists("planes"))
            return 0;
        const Setting& planes = primitives["planes"];
        const Setting& plane = planes[index];

        plane.lookupValue("position", l_position);

        return l_position;
    }
    /**
     * Retrieves the color of a plane at the specified index.
     *
     * @param index The index of the plane.
     * @return The color of the plane as a Color object.
     */
    [[nodiscard]] Color planeColorGet(const ui32 index)
    {
        d64 rgb[3] = {0};
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        if (!primitives.exists("planes"))
            return {0, 0, 0};
        const Setting& planes = primitives["planes"];
        const Setting& plane = planes[index];
        const Setting& color = plane.lookup("color");

        color.lookupValue("r", rgb[0]);
        color.lookupValue("g", rgb[1]);
        color.lookupValue("b", rgb[2]);

        return {rgb[0], rgb[1], rgb[2]};
    }
    /**
     * @brief Get the number of planes in the configuration file.
     *
     * @return The number of planes.
     */
    [[nodiscard]] ui32 nbPlaneGet(void)
    {
        if (!getRoot()["primitives"].exists("planes"))
            return 0;
        return getRoot()["primitives"]["planes"].getLength();
    }

    /**
     * @brief Retrieves the position of a specific cone from the configuration file.
     *
     * @param index The index of the cone.
     * @return The position of the cone as a Position object.
     */
    [[nodiscard]] Position withConePositionGet(const ui32 index)
    {
        d64 x = 0, y = 0, z = 0;
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        const Setting& cones = primitives["cones"];
        const Setting& cone = cones[index];

        cone.lookupValue("x", x);
        cone.lookupValue("y", y);
        cone.lookupValue("z", z);
        return {x, y, z};
    }

    /**
     * @brief Retrieves the radius of a specific cone from the configuration file.
     *
     * @param index The index of the cone.
     * @return The radius of the cone as a double.
     */
    [[nodiscard]] d64 withConeRadiusGet(const ui32 index)
    {
        d64 radius = 0;
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        const Setting& cones = primitives["cones"];
        const Setting& cone = cones[index];

        cone.lookupValue("r", radius);
        return radius;
    }

    /**
     * @brief Retrieves the depth of a specific cone from the configuration file.
     *
     * @param index The index of the cone.
     * @return The depth of the cone as a double.
     */
    [[nodiscard]] d64 withConeDepthGet(const ui32 index)
    {
        d64 depth = 0;
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        const Setting& cones = primitives["cones"];
        const Setting& cone = cones[index];

        cone.lookupValue("height", depth);
        return depth;
    }

    /**
     * @brief Retrieves the material of a specific cone from the configuration file.
     *
     * @param index The index of the cone.
     * @return The material of the cone as a PMaterial object.
     */
    [[nodiscard]] PMaterial withConeMaterialGet(const ui32 index)
    {
        std::string sType;
        PMaterial pcylindre;
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        const Setting& cones = primitives["cones"];
        const Setting& cone = cones[index];
        const Setting& material = cone.lookup("material");

        material.lookupValue("type", sType);
        pcylindre.nameSet(sType);

        if (material.exists("textures"))
        {
            PTexture ptexture(sType);
            d64 scale = 0.0;
            const Setting& textures = material.lookup("textures");

            pcylindre.istextureSet(true);
            textures.lookupValue("scale", scale);
            ptexture.scaleSet(scale);

            const Setting& colors = textures.lookup("colors");
            for (ui32 i = 0; i != colors.getLength(); ++i) {
                d64 rgb[3] = {0};
                colors[i].lookupValue("r", rgb[0]);
                colors[i].lookupValue("g", rgb[1]);
                colors[i].lookupValue("b", rgb[2]);
                ptexture.colorsSet((Math::Vector<3>({rgb[0], rgb[1], rgb[2]})));
            }
            pcylindre.addTexture(ptexture);
        }
        if (material.exists("color"))
        {
            d64 rgb[3] = {0.0};
            const Setting& color = material.lookup("color");
            pcylindre.isColorSet(true);
            color.lookupValue("r", rgb[0]);
            color.lookupValue("g", rgb[1]);
            color.lookupValue("b", rgb[2]);
            pcylindre.addColor(PColor(sType, Math::Vector<3>({rgb[0], rgb[1], rgb[2]})));
        }
        if (material.exists("refractive"))
        {
            pcylindre.isRefractiveSet(true);
            d64 refractive_index = 0.0;
            const Setting& color = material.lookup("refractive");
            color.lookupValue("refractive_index", refractive_index);
            pcylindre.addRefractive(PRefractive(sType, refractive_index));
        }
        return std::move(pcylindre);
    }


    [[nodiscard]] Position withDiskCenterGet(const ui32 index)
    {
        const Setting& root = _cfg.getRoot();
        const Setting& primitives = _cfg.lookup("primitives");
        const Setting& disks = primitives["disks"];
        const Setting& disk = disks[index];
        const Setting& center = disk.lookup("center");
        d64 x = 0, y = 0, z = 0;

        std::cout << "center = {x = 1.0; y = 2.0; z = 3.0;};" << std::endl;

        center.lookupValue("x", x);
        center.lookupValue("y", y);
        center.lookupValue("z", z);
        std::cout << x << y << z << std::endl;
        return {x, y, z};
    }
    [[nodiscard]] Position withDiskNormalGet(const ui32 index)
    {
        const Setting& root = _cfg.getRoot();
        const Setting& primitives = _cfg.lookup("primitives");
        const Setting& disks = primitives["disks"];
        const Setting& disk = disks[index];
        const Setting& normal = disk.lookup("normal");
        d64 x = 0, y = 0, z = 0;

        std::cout << "normal = {x = 4.0; y = 5.0; z = 9.0;};" << std::endl;

        normal.lookupValue("x", x);
        normal.lookupValue("y", y);
        normal.lookupValue("z", z);
        std::cout << x << y << z << std::endl;
        return {x, y, z};
    }
    [[nodiscard]] d64 withDiskRadiusGet(const ui32 index)
    {
        d64 radius = 0;
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        const Setting& disks = primitives["disks"];
        const Setting& disk = disks[index];

        disk.lookupValue("r", radius);
        return radius;
    }
    [[nodiscard]] PMaterial withDiskMaterialGet(const ui32 index)
    {
        std::string sType;
        PMaterial pcylindre;
        const Setting& root = getRoot();
        const Setting& primitives = root["primitives"];
        const Setting& disks = primitives["disks"];
        const Setting& disk = disks[index];
        const Setting& material = disk.lookup("material");

        material.lookupValue("type", sType);
        pcylindre.nameSet(sType);

        if (material.exists("textures"))
        {
            PTexture ptexture(sType);
            d64 scale = 0.0;
            const Setting& textures = material.lookup("textures");

            pcylindre.istextureSet(true);
            textures.lookupValue("scale", scale);
            ptexture.scaleSet(scale);

            const Setting& colors = textures.lookup("colors");
            for (ui32 i = 0; i != colors.getLength(); ++i) {
                d64 rgb[3] = {0};
                colors[i].lookupValue("r", rgb[0]);
                colors[i].lookupValue("g", rgb[1]);
                colors[i].lookupValue("b", rgb[2]);
                ptexture.colorsSet((Math::Vector<3>({rgb[0], rgb[1], rgb[2]})));
            }
            pcylindre.addTexture(ptexture);
        }
        if (material.exists("color"))
        {
            d64 rgb[3] = {0.0};
            const Setting& color = material.lookup("color");
            pcylindre.isColorSet(true);
            color.lookupValue("r", rgb[0]);
            color.lookupValue("g", rgb[1]);
            color.lookupValue("b", rgb[2]);
            pcylindre.addColor(PColor(sType, Math::Vector<3>({rgb[0], rgb[1], rgb[2]})));
        }
        if (material.exists("refractive"))
        {
            pcylindre.isRefractiveSet(true);
            d64 refractive_index = 0.0;
            const Setting& color = material.lookup("refractive");
            color.lookupValue("refractive_index", refractive_index);
            pcylindre.addRefractive(PRefractive(sType, refractive_index));
        }
        return std::move(pcylindre);
    }

    /*      Lights section   */

    /**
     * @brief Retrieves the ambient light value from the configuration file.
     *
     * @return The ambient light value as a float.
     */
    [[nodiscard]] Position withLightDirectionnalCenterGet(const ui32 index)
    {
        const Setting& root = getRoot();
        const Setting& lights = root["lights"];
        const Setting& directionals = lights["directional"];
        const Setting& directional = directionals[index];
        const Setting& center = directional.lookup("center");
        d64 x = 0, y = 0, z = 0;

        center.lookupValue("x", x);
        center.lookupValue("y", y);
        center.lookupValue("z", z);
        return {x, y, z};
    }
    /**
     * @brief Gets the value of the diffuse property for lights.
     *
     * @return The value of the diffuse property for lights.
     */
    [[nodiscard]] Position withLightDirectionnalNormalGet(const ui32 index)
    {
        const Setting& root = getRoot();
        const Setting& lights = root["lights"];
        const Setting& directionals = lights["directional"];
        const Setting& directional = directionals[index];
        const Setting& normal = directional.lookup("normal");
        d64 x = 0, y = 0, z = 0;

        normal.lookupValue("x", x);
        normal.lookupValue("y", y);
        normal.lookupValue("z", z);

        return {x, y, z};
    }
    [[nodiscard]] d64 withLightDirectionnalRadiusGet(const ui32 index)
    {
        d64 radius = 0;
        const Setting& root = getRoot();
        const Setting& lights = root["lights"];
        const Setting& directionals = lights["directional"];
        const Setting& directional = directionals[index];

        directional.lookupValue("r", radius);

        return radius;
    }
    /**
     * @brief Retrieves the coordinates of a point light source at the specified index.
     *
     * @param index The index of the point light source.
     * @return The coordinates of the point light source as a Point object.
     */
    [[nodiscard]] PMaterial withLightDirectionnalMaterialGet(const ui32 index)
    {
        d64 rgb[3] = {0};
        i32 l_point[3] = {0};
        PMaterial lLight;
        const Setting& root = getRoot();
        const Setting& lights = root["lights"];
        const Setting& directionals = lights["directional"];
        const Setting& directional = directionals[index];
        const Setting& color = directional.lookup("color");

        color.lookupValue("r", rgb[0]);
        color.lookupValue("g", rgb[1]);
        color.lookupValue("b", rgb[2]);

        lLight.nameSet("Directionnal");
        lLight.addColor(PColor("Directionnal", Math::Vector<3>({rgb[0], rgb[1], rgb[2]})));

        return std::move(lLight);
    }

    /**
     * @brief Retrieves the ambient light value from the configuration file.
     *
     * @return The ambient light value as a float.
     */
    [[nodiscard]] Position withLightDiffuseCenterGet(const ui32 index)
    {
        const Setting& root = getRoot();
        const Setting& lights = root["lights"];
        const Setting& diffuses = lights["diffuse"];
        const Setting& diffuse = diffuses[index];
        const Setting& center = diffuse.lookup("center");
        d64 x = 0, y = 0, z = 0;

        center.lookupValue("x", x);
        center.lookupValue("y", y);
        center.lookupValue("z", z);

        return {x, y, z};
    }
    /**
     * @brief Gets the value of the diffuse property for lights.
     *
     * @return The value of the diffuse property for lights.
     */
    [[nodiscard]] Position withLightDiffuseNormalGet(const ui32 index)
    {
        const Setting& root = getRoot();
        const Setting& lights = root["lights"];
        const Setting& diffuses = lights["diffuse"];
        const Setting& diffuse = diffuses[index];
        const Setting& normal = diffuse.lookup("normal");
        d64 x = 0, y = 0, z = 0;

        normal.lookupValue("x", x);
        normal.lookupValue("y", y);
        normal.lookupValue("z", z);

        return {x, y, z};
    }
    [[nodiscard]] d64 withLightDiffuseRadiusGet(const ui32 index)
    {
        d64 radius = 0;
        const Setting& root = getRoot();
        const Setting& lights = root["lights"];
        const Setting& diffuses = lights["diffuse"];
        const Setting& diffuse = diffuses[index];

        diffuse.lookupValue("r", radius);
        return radius;
    }
    /**
     * @brief Retrieves the coordinates of a point light source at the specified index.
     *
     * @param index The index of the point light source.
     * @return The coordinates of the point light source as a Point object.
     */
    [[nodiscard]] PMaterial withLightDiffuseMaterialGet(const ui32 index)
    {
        d64 rgb[3] = {0};
        i32 l_point[3] = {0};
        PMaterial lLight;
        const Setting& root = getRoot();
        const Setting& lights = root["lights"];
        const Setting& diffuses = lights["diffuse"];
        const Setting& diffuse = diffuses[index];
        const Setting& color = diffuse.lookup("color");

        color.lookupValue("r", rgb[0]);
        color.lookupValue("g", rgb[1]);
        color.lookupValue("b", rgb[2]);
        lLight.nameSet("Diffuse");
        lLight.addColor(PColor("Diffuse", Math::Vector<3>({rgb[0], rgb[1], rgb[2]})));

        return std::move(lLight);
    }
};

#endif /* !CFGPARSER_HPP_ */
