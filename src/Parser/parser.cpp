// /*
// ** EPITECH PROJECT, 2024
// ** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
// ** File description:
// ** parser
// */

// #include <iostream>
// #include <filesystem>
// #include <libconfig.h++>
// #include "Parser/CFGParser.hpp"
// #include "Parser/PrimitivesBuilder.hpp"
// #include "Parser/CameraBuilder.hpp"
// #include "Parser/LightsBuilder.hpp"
// #include "Parser/CFGParser.hpp"
// #include "Parser/CFGParser.hpp"
// #include "Parser/ArgumentManager.hpp"

// using namespace libconfig;

// int _main(int ac, char **av)
// {
//     ArgumentManager args(ac, av);
//     try {
//         CFGParser parser(args.fileNameGet());

//         CameraBuilder cbuilder;
//         Camera camera = cbuilder
//             .withResolution(parser.cameraResolutionGet())
//             .withPosition(std::get<0>(parser.cameraPositionGet()), std::get<1>(parser.cameraPositionGet()), std::get<2>(parser.cameraPositionGet()))
//             .withRotation(std::get<0>(parser.cameraRotationGet()), std::get<1>(parser.cameraRotationGet()), std::get<2>(parser.cameraRotationGet()))
//             .withFieldOfView(parser.fieldOfViewGet())
//             .build();
//         camera.print();

//         PrimitivesBuilder pbuilder;
//         for (uint32_t i = 0; i < parser.nbSphereGet(); ++i) {
//             pbuilder.addSphere(parser.spherePositionGet(i),
//                                 parser.sphereRadiusGet(i),
//                                 parser.sphereColorGet(i),
//                                 parser.sphereRotationGet(i),
//                                 parser.sphereTranslationGet(i),
//                                 parser.sphereMaterialGet(i));
//         }
//         for (uint32_t i = 0; i < parser.nbPlaneGet(); ++i) {
//             pbuilder.addPlane(parser.planeAxisGet(i), parser.planePositionGet(i), parser.planeColorGet(i));
//         }
//         pbuilder.print();

//         LightsBuilder lbuilder;
//         lbuilder
//             .ambientSet(parser.lightsAmbientGet())
//             .diffuseSet(parser.lightsDiffuseGet())
//             .directionalSet();
//         for (uint32_t i = 0; i < parser.nbLightsGet(); ++i) {
//             lbuilder.addPoint(parser.lightsPointGet(i));
//         }

//         Lights lights = lbuilder.build();
//         lights.print();
//     }
//     catch (const ParseException &pex)
//     {
//         std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
//         return EXIT_FAILURE;
//     }
//     catch (const SettingNotFoundException &nfex)
//     {
//         std::cerr << "Setting not found: " << nfex.getPath() << std::endl;
//         return EXIT_FAILURE;
//     }
//     catch (const FileIOException &fioex)
//     {
//         std::cerr << "File not found: " << std::endl;
//         return EXIT_FAILURE;
//     }
//     return 0;
// }
