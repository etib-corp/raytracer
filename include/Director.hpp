/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Director
*/

#ifndef DIRECTOR_HPP_
#define DIRECTOR_HPP_

#include <iostream>
#include <filesystem>
#include <libconfig.h++>
#include "Parser/CFGParser.hpp"
#include "Parser/PrimitivesBuilder.hpp"
#include "Parser/CameraBuilder.hpp"
#include "Parser/LightBuilder.hpp"
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

class Director
{
    using ui32 = uint32_t;
    public:
        Director(const ArgumentManager& args) : _args(args)
        {
        }

        Camera getCamera(void)
        {
            CFGParser parser(_args.fileNameGet());
            CameraBuilder cbuilder;
            Camera camera = cbuilder
                .withResolution(parser.cameraResolutionGet())
                .withPositionFrom(std::get<0>(parser.cameraPositionGet()), std::get<1>(parser.cameraPositionGet()), std::get<2>(parser.cameraPositionGet()))
                .withPositionAt(std::get<0>(parser.cameraPositionAtGet()), std::get<1>(parser.cameraPositionAtGet()), std::get<2>(parser.cameraPositionAtGet()))
                .withRotation(std::get<0>(parser.cameraRotationGet()), std::get<1>(parser.cameraRotationGet()), std::get<2>(parser.cameraRotationGet()))
                .withFieldOfView(parser.fieldOfViewGet())
                .withMaxDepth(parser.cameraMaxDepthGet())
                .withSamplePerPixel(parser.cameraSamplePerPixelGet())
                .withLight(parser.cameraLightGet())
                .withBackgroundColor(parser.cameraBackgroundColorGet())
                .build();
            return std::move(camera);
        }
        ObjectsList getObjectsList(void)
        {
            CFGParser parser(_args.fileNameGet());
            PrimitivesBuilder pbuilder;
            LightBuilder lbuilder;

            ObjectsList word;
            for (ui32 i = 0; i < parser.nbSphereGet(); ++i) {
                pbuilder.addSphere(parser.withSpherePositionGet(i),
                                    parser.withSphereRadiusGet(i),
                                    parser.withSphereColorGet(i),
                                    parser.withSphereRotationGet(i),
                                    parser.withSphereTranslationGet(i),
                                    parser.withSphereMaterialGet(i));
            }
            for (ui32 i = 0; i < parser.nbCylindreGet(); ++i) {
                pbuilder.addCylindre(parser.withCylindrePositionGet(i),
                                    parser.withCylindreRadiusGet(i),
                                    parser.withCylindreDepthGet(i),
                                    parser.withCylindreMaterialGet(i));
            }
            for (ui32 i = 0; i < parser.nbConeGet(); ++i) {
                pbuilder.addCone(parser.withConePositionGet(i),
                                    parser.withConeRadiusGet(i),
                                    parser.withConeDepthGet(i),
                                    parser.withConeMaterialGet(i));
            }
            for (ui32 i = 0; i < parser.nbDiskGet(); ++i) {
                pbuilder.addDisk(parser.withDiskCenterGet(i),
                                    parser.withDiskNormalGet(i),
                                    parser.withDiskRadiusGet(i),
                                    parser.withDiskMaterialGet(i));
            }
            for (ui32 i = 0; i < parser.nbPlaneGet(); ++i) {
                pbuilder.addPlane(parser.planeAxisGet(i), parser.planePositionGet(i), parser.planeColorGet(i));
            }
            for (ui32 i = 0; i < parser.nbLightDirectionalGet(); ++i) {
                pbuilder.addLight(parser.withLightDirectionnalCenterGet(i),
                                    parser.withLightDirectionnalNormalGet(i),
                                    parser.withLightDirectionnalRadiusGet(i),
                                    parser.withLightDirectionnalMaterialGet(i));
            }
            for (ui32 i = 0; i < parser.nbLightDiffuseGet(); ++i) {
                pbuilder.addLight(parser.withLightDiffuseCenterGet(i),
                                    parser.withLightDiffuseNormalGet(i),
                                    parser.withLightDiffuseRadiusGet(i),
                                    parser.withLightDiffuseMaterialGet(i));
            }
            word = pbuilder.build();
            return word;
        }
    private:
        ArgumentManager _args;
};

#endif /* !DIRECTOR_HPP_ */
