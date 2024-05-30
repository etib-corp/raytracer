/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include <iostream>
#include <filesystem>
#include <libconfig.h++>
#include "Parser/CFGParser.hpp"
#include "Parser/PrimitivesBuilder.hpp"
#include "Parser/CameraBuilder.hpp"
#include "Parser/LightsBuilder.hpp"
#include "Parser/CFGParser.hpp"
#include "Parser/CFGParser.hpp"

#include "raytracer.hpp"
#include "Color.hpp"
#include "Primitive/Cone.hpp"
#include "Vector.hpp"
#include "Ray.hpp"
#include "Primitive/Sphere.hpp"
#include "Primitive/ObjectsList.hpp"
#include "Primitive/Plan.hpp"
#include "Primitive/Cylindre.hpp"
#include "Primitive/Disk.hpp"
#include "Material/Metal.hpp"
#include "Material/Lambertian.hpp"
#include "Material/Dielectric.hpp"
#include "Texture/SolidColor.hpp"
#include "Texture/Checker.hpp"
#include "Parser/ArgumentManager.hpp"
#include "Light/Diffuse.hpp"
#include "Light/Directionnal.hpp"
#include "Director.hpp"

void default_world(int ac, char **av)
{
    ObjectsList world;


    auto checker = std::make_shared<Checker>((6.4), Color(0, 0, 0), Color(1, 1, 1));
    world.add(std::make_shared<Sphere>(Math::Vector<3>({0,-1000,0}), 1000, std::make_shared<Lambertian>(checker)));

    auto material1 = std::make_shared<Dielectric>(1.5);

    // world.add(std::make_shared<Sphere>(Math::Vector<3>({0, 1, 0}), 1.0, material1));

    // auto material2 = std::make_shared<Lambertian>(Color(0.4, 0.2, 0.1));
    auto material2 = std::make_shared<Lambertian>(Color(1.0, 0.0, 0.0));
    auto material3 = std::make_shared<Metal>(Color(0.7, 0.6, 0.5), 0.0);
    auto material4 = std::make_shared<Metal>(Color(0.7, 0.6, 0.5), 0.0);

    // world.add(std::make_shared<Disk>(Math::Vector<3>({0, 1, -5}), Math::Vector<3>({0, 0.1, 1}), 1.0, material3));

    // world.add(std::make_shared<Sphere>(Math::Vector<3>({-4, 1, 0}), 1.0, material2));

    // world.add(std::make_shared<Sphere>(Math::Vector<3>({4, 1, 0}), 1.0, material3));

    world.add(std::make_shared<Cylindre>(Math::Vector<3>({0, 3, 0}), 2, 1.0, material4));

    Camera cam(Math::Vector<2>({1000, 572}));

    cam.setSamplesPerPixel(32); // 500
    cam.setMaxDepth(50);

    cam.setVfov(70.0);
    cam.setLookFrom(Math::Vector<3>({0, 0, 5}));
    cam.setLookAt(Math::Vector<3>({0, 3, 0}));
    cam.setVup(Math::Vector<3>({0, 1, 0}));
    cam.setLightEnabled(false);


    cam.renderSFML(world);
}

void default_world_better()
{
    ObjectsList world;


    auto checker = std::make_shared<Checker>((6.4), Color(0,0,0), Color(1,1,1));
    world.add(std::make_shared<Sphere>(Math::Vector<3>({0,-1000,0}), 1000, std::make_shared<Lambertian>(checker)));

    auto material1 = std::make_shared<Dielectric>(1.5);


    auto material2 = std::make_shared<Lambertian>(Color(1.0, 0.0, 0.0));
    auto material3 = std::make_shared<Metal>(Color(0.7, 0.6, 0.5), 0.0);



    world.add(std::make_shared<Sphere>(Math::Vector<3>({4, 3, 1}), 1.0, material3));

    world.add(std::make_shared<Cylindre>(Math::Vector<3>({0, 2, 0}), 2, 1.0, material3));

    world.add(std::make_shared<Cone>(Math::Vector<3>({-4, 2, 1}), 4, 2.0, material2));

    Camera cam(Math::Vector<2>({WIDTH, HEIGHT}));

    cam.setSamplesPerPixel(4);
    cam.setMaxDepth(50);

    cam.setVfov(70.0);
    cam.setLookFrom(Math::Vector<3>({0, 1, 5}));
    cam.setLookAt(Math::Vector<3>({0, 2, 0}));
    cam.setVup(Math::Vector<3>({0, 1, 0}));

    cam.setLightEnabled(false);

    cam.renderSFML(world);
}

void checkred_spheres()
{
    ObjectsList world;

    Camera cam(Math::Vector<2>({WIDTH, HEIGHT}));

    cam.setVfov(40.0);
    cam.setLookFrom(Math::Vector<3>({0,2,13}));
    cam.setLookAt(Math::Vector<3>({0,0,0}));
    cam.setVup(Math::Vector<3>({0,1,0}));

    cam.setDefocusAngle(0.0);
    cam.setLightEnabled(false);


    cam.renderSFML(world);
}

void light()
{
    ObjectsList world;

    auto material1 = std::make_shared<Lambertian>(Color(1, 0, 0));
    world.add(std::make_shared<Sphere>(Math::Vector<3>({0, 0.5, 0}), 1, material1));

    auto material2 = std::make_shared<Lambertian>(Color(0, 1, 0));
    world.add(std::make_shared<Sphere>(Math::Vector<3>({-3.5, 4, 0}), 1, material2));

    auto material3 = std::make_shared<Lambertian>(Color(0, 0, 1));
    world.add(std::make_shared<Sphere>(Math::Vector<3>({3.5, 4, 0}), 1, material3));

    auto material4 = std::make_shared<Checker>(0.32, Color(1, 0, 0), Color(0.9, 0.9, 0.9));
    world.add(std::make_shared<Sphere>(Math::Vector<3>({0, 7.5, 0}), 1, std::make_shared<Lambertian>(material4)));

    auto light1 = std::make_shared<Diffuse>(Color(4, 4, 4));
    auto light2 = std::make_shared<Directionnal>(Color(4, 4, 4));
    world.add(std::make_shared<Sphere>(Math::Vector<3>({0, 4, 0}), 2, light1));
    world.add(std::make_shared<Disk>(Math::Vector<3>({0, 4, 0}), Math::Vector<3>({1, 1, 0}), 2, light2));
    world.add(std::make_shared<Cylindre>(Math::Vector<3>({0, 8, 0}), 12, 1.0, material1));


    Camera cam(Math::Vector<2>({WIDTH, HEIGHT}));

    cam.setVfov(40.0);
    cam.setLookFrom(Math::Vector<3>({0,3,6}));
    cam.setLookAt(Math::Vector<3>({0,2,0}));
    cam.setVup(Math::Vector<3>({0,1,0}));

    cam.setBackgroundColor(Color(0, 0, 0));

    cam.setDefocusAngle(0.0);
    cam.setLightEnabled(true);
    cam.print();
    cam.renderSFML(world);
}

int main(int ac, char **av)
{
    ArgumentManager args(ac, av);
    try
    {
        Director director(args);
        ObjectsList world = director.getObjectsList();

        Camera cam = director.getCamera();
        cam.setCamera();
        cam.print();
        world.print();
        cam.renderSFML(world);
    }
    catch (const ParseException &pex)
    {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
        return EXIT_FAILURE;
    }
    catch (const SettingNotFoundException &nfex)
    {
        std::cerr << "Setting not found: " << nfex.getPath() << std::endl;
        return EXIT_FAILURE;
    }
    catch (const FileIOException &fioex)
    {
        std::cerr << "File not found: " << std::endl;
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "Error in file" << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
