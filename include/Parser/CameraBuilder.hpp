/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** CameraBuilder
*/

#ifndef CAMERABUILDER_HPP_
#define CAMERABUILDER_HPP_

#include <bits/stdc++.h>
#include "../Camera.hpp"
#include "../Vector.hpp"

/**
 * @class CameraBuilder
 * @brief A builder class for constructing Camera objects.
 *
 * The CameraBuilder class provides a convenient way to construct Camera objects
 * with various configuration options.
 */
class CameraBuilder {
    using i32 = int32_t;
    using d64 = double;
    public:
        CameraBuilder() = default;
        ~CameraBuilder() = default;

        /**
         * @brief Sets the resolution of the camera.
         *
         * This function sets the resolution of the camera by taking a pair of doubles representing the width and height of the image.
         *
         * @param resolution A pair of doubles representing the width and height of the image.
         * @return A reference to the CameraBuilder object.
         */
        [[nodiscard]] CameraBuilder& withResolution(const std::pair<d64, d64>& resolution)
        {
            camera_.setImageDimension(Math::Vector<2>({resolution.first, resolution.second}));
            return *this;
        }

        /**
         * @brief Sets the position of the camera using the specified coordinates.
         *
         * @param x The x-coordinate of the camera position.
         * @param y The y-coordinate of the camera position.
         * @param z The z-coordinate of the camera position.
         * @return A reference to the CameraBuilder object.
         */
        [[nodiscard]] CameraBuilder& withPositionFrom(const d64& x, const d64& y, const d64& z)
        {
            camera_.setLookFrom(Math::Vector<3>({x, y, z}));
            return *this;
        }

        /**
         * @brief Sets the position of the camera at the specified coordinates.
         *
         * @param x The x-coordinate of the camera position.
         * @param y The y-coordinate of the camera position.
         * @param z The z-coordinate of the camera position.
         * @return A reference to the CameraBuilder object.
         */
        [[nodiscard]] CameraBuilder& withPositionAt(const d64& x, const d64& y, const d64& z)
        {
            camera_.setLookAt(Math::Vector<3>({x, y, z}));
            return *this;
        }

        /**
         * @brief Sets the rotation of the camera.
         *
         * This function sets the rotation of the camera using the provided x, y, and z values.
         *
         * @param x The rotation value along the x-axis.
         * @param y The rotation value along the y-axis.
         * @param z The rotation value along the z-axis.
         * @return A reference to the CameraBuilder object.
         */
        [[nodiscard]] CameraBuilder& withRotation(const i32 x, const i32 y, const i32 z) noexcept
        {
            camera_.setVup(Math::Vector<3>({static_cast<d64>(x), static_cast<d64>(y), static_cast<d64>(z)}));
            return *this;
        }

        /**
         * @brief Sets the field of view for the camera.
         *
         * This function sets the vertical field of view (FOV) for the camera.
         * The FOV determines how much of the scene is visible through the camera.
         *
         * @param fov The field of view in degrees.
         * @return A reference to the CameraBuilder object.
         */
        [[nodiscard]] CameraBuilder& withFieldOfView(const float fov) noexcept
        {
            camera_.setVfov(static_cast<d64>(fov));
            return *this;
        }

        /**
         * @brief Sets the maximum depth of the camera.
         *
         * This function sets the maximum depth of the camera, which determines the maximum number of recursive ray bounces.
         *
         * @param maxDepth The maximum depth value to set.
         * @return A reference to the CameraBuilder object.
         */
        [[nodiscard]] CameraBuilder& withMaxDepth(const i32 maxDepth) noexcept
        {
            camera_.setMaxDepth(maxDepth);
            return *this;
        }

        /**
         * @brief Sets the number of samples per pixel for the camera.
         *
         * This function sets the number of samples per pixel for the camera. It takes an integer parameter `samplePerPixel`
         * which represents the number of samples per pixel. The function updates the camera's samples per pixel value and
         * returns a reference to the `CameraBuilder` object.
         *
         * @param samplePerPixel The number of samples per pixel for the camera.
         * @return A reference to the `CameraBuilder` object.
         */
        [[nodiscard]] CameraBuilder& withSamplePerPixel(const i32 samplePerPixel) noexcept
        {
            camera_.setSamplesPerPixel(samplePerPixel);
            return *this;
        }

        /**
         * @brief Sets whether the light is enabled for the camera.
         *
         * @param lightEnable A boolean indicating whether the light is enabled.
         * @return A reference to the CameraBuilder object.
         */
        [[nodiscard]] CameraBuilder& withLight(const bool& lightEnable)
        {
            camera_.setLightEnabled(lightEnable);
            return *this;
        }

        /**
         * @brief Sets the background color of the camera.
         *
         * This function sets the background color of the camera to the specified color.
         *
         * @param color The color to set as the background color.
         * @return A reference to the CameraBuilder object.
         */
        [[nodiscard]] CameraBuilder& withBackgroundColor(const Color& color)
        {
            camera_.setBackgroundColor(color);
            return *this;
        }

        /**
         * @brief Builds and returns the Camera object.
         *
         * @return The built Camera object.
         */
        [[nodiscard]] Camera build(void)
        {
            return camera_;
        }

    private:
        /**
         * @brief Represents a camera used in ray tracing.
         *
         * The `Camera` class encapsulates the properties and behavior of a camera used in ray tracing.
         * It defines the position, orientation, and other parameters necessary to generate rays for rendering a scene.
         */
        Camera camera_;
};

#endif /* !CAMERABUILDER_HPP_ */
