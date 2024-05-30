/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** AEditDouble3
*/

#ifndef AEDITDOUBLE3_HPP_
#define AEDITDOUBLE3_HPP_

#include "GUI/AInput.hpp"

namespace GUI {
    /**
     * @class AEditDouble3
     * @brief AEditDouble3 class for editing 3D coordinates.
     *
     * This class is used to edit 3D coordinates (x, y, z) in a graphical user interface.
     *
     * @author Julien Ferdinand
     * @date 2024
     */
    class AEditDouble3 : public AInput {
        public:
            /**
             * @brief Virtual destructor.
             */
            virtual ~AEditDouble3() = default;

            /**
             * @brief Get the x coordinate.
             *
             * @return The x coordinate.
             */
            float getX() const;

            /**
             * @brief Get the y coordinate.
             *
             * @return The y coordinate.
             */
            float getY() const;

            /**
             * @brief Get the z coordinate.
             *
             * @return The z coordinate.
             */
            float getZ() const;

            /**
             * @brief Set the x coordinate.
             *
             * @param value The new x coordinate.
             */
            void setX(float value);

            /**
             * @brief Set the y coordinate.
             *
             * @param value The new y coordinate.
             */
            void setY(float value);

            /**
             * @brief Set the z coordinate.
             *
             * @param value The new z coordinate.
             */
            void setZ(float value);

        protected:
            float _x;
            float _y;
            float _z;
    };
}

#endif /* !AEDITDOUBLE3_HPP_ */
