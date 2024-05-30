/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** ArgumentManager
*/

#include "Parser/ArgumentManager.hpp"

ArgumentManager::ArgumentManager(i32 ac, char **av)
{
    if (!hasNbValidArgument(ac))
        help(EXIT_FAILURE);
    std::filesystem::path filename(FILENAME[av]);
    _filename = filename;
    if (hasHelpFlag())
    {
        help(EXIT_SUCCESS);
    }
    if (!hasValidExtension())
    {
        throw "Bad format/extension";
    }
}

ArgumentManager::~ArgumentManager()
{
}

std::string ArgumentManager::fileNameGet(void)
{
    return _filename.string();
}

[[noreturn]] void ArgumentManager::help(i32 exitCode)
{
    std::cout << "USAGE: ./raytracer <SCENE_FILE>"
                << "SCENE_FILE: scene configuration" << std::endl;
    exit(exitCode);
}

[[nodiscard]] bool ArgumentManager::hasNbValidArgument(i32 ac)
{
    return (ac == 2);
}
[[nodiscard]] bool ArgumentManager::hasValidExtension(void)
{
    std::string extension = _filename.extension().string();
    return (extension == ".cfg" || extension == ".etib");
}
[[nodiscard]] bool ArgumentManager::hasHelpFlag(void)
{
    return (_filename.filename().string().find("--help") != std::string::npos);
}
