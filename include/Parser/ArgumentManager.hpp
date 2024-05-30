/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** ArgumentManager
*/

#ifndef ARGUMENTMANAGER_HPP_
#define ARGUMENTMANAGER_HPP_

#include <bits/stdc++.h>
#define FILENAME 1

/**
 * @class ArgumentManager
 * @brief A class that manages command line arguments.
 */
class ArgumentManager {
    using i32 = int32_t;
    public:
        /**
         * @brief Constructs an ArgumentManager object.
         * @param ac The number of command line arguments.
         * @param av The array of command line arguments.
         */
        ArgumentManager(i32 ac, char **av);

        /**
         * @brief Destroys the ArgumentManager object.
         */
        ~ArgumentManager();

        /**
         * @brief Gets the file name from the command line arguments.
         * @return The file name as a string.
         */
        [[nodiscard]] std::string fileNameGet(void);

    protected:
        /**
         * @brief Displays the help message and exits the program.
         * @param exitCode The exit code to be returned.
         * @noreturn This function does not return.
         */
        [[noreturn]] void help(i32 exitCode);

    private:
        std::filesystem::path _filename;

        /**
         * @brief Checks if the number of arguments is valid.
         * @param ac The number of command line arguments.
         * @return True if the number of arguments is valid, false otherwise.
         */
        [[nodiscard]] bool hasNbValidArgument(i32 ac);

        /**
         * @brief Checks if the file has a valid extension.
         * @return True if the file has a valid extension, false otherwise.
         */
        [[nodiscard]] bool hasValidExtension(void);

        /**
         * @brief Checks if the help flag is present in the command line arguments.
         * @return True if the help flag is present, false otherwise.
         */
        [[nodiscard]] bool hasHelpFlag(void);
};

#endif /* !ARGUMENTMANAGER_HPP_ */
