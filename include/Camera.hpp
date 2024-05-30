/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Camera
*/

#pragma once

#include "raytracer.hpp"
#include "Rectangle.hpp"
#include "Color.hpp"
#include "Ray.hpp"
#include "AObject.hpp"
#include "APrimitive.hpp"
#include "Primitive/ObjectsList.hpp"
#include "Primitive/Sphere.hpp"
#include "Material/Lambertian.hpp"
#include "Texture/Checker.hpp"

#include "imgui.h"
#include "imgui-SFML.h"

#include "RaytracerAth/RaytracerAth.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <thread>
#include <memory>

#define ASPECT_RATIO (16.0 / 9.0)

#define WIDTH 128 // 128 for real time rendering
#define RENDER_WIDTH 1000

#define HEIGHT static_cast<int>(WIDTH / ASPECT_RATIO)
#define RENDER_HEIGHT static_cast<int>(RENDER_WIDTH / ASPECT_RATIO)

#define VIEWPORT_HEIGHT 2.0
#define VIEWPORT_WIDTH (VIEWPORT_HEIGHT * (double(WIDTH) / double(HEIGHT)))

#define NB_THREADS 512

/**
 * @class Camera
 * @brief The Camera class represents a virtual camera in a 3D scene.
 *
 * It is responsible for generating rays based on the camera's viewport, field of view, and any applied filters.
 */
class Camera : public AObject {
    public:
        Camera();
        /**
        * @brief Construct a new Camera object.
        *
        * This constructor initializes the camera with a default viewport, field of view, and no filter applied.
        */
        Camera(const Math::Vector<2>& imageDimension);

        /**
        * @brief Destroy the Camera object.
        *
        * This destructor cleans up any resources allocated by the camera.
        */
        ~Camera();

        void init();
        void setCamera(void);
        /**
        * @brief Generate a ray from the camera based on the given coordinates.
        *
        * @param x The x-coordinate of the ray origin.
        * @param y The y-coordinate of the ray origin.
        * @return A Ray object representing the ray generated from the camera.
        */
        Ray ray(double x, double y) const;

        /**
         * @brief Render the world from the camera's perspective.
         *
         * @param world The world to render.
        */
        std::chrono::_V2::system_clock::time_point render(const APrimitive& world);

        /**
         * @brief Render the world from the camera's perspective.
         *
         * @param world The world to render.
        */
        void renderSFML(ObjectsList& world);

        bool checkMove(sf::Event event);

        /**
         * @brief Get the viewport of the camera.
         *
         * @return The viewport of the camera.
        */
        Math::Rectangle getViewport() const;

        /**
         * @brief Get the dimension of the output image.
         *
         * @return The dimension of the output image.
        */
        Math::Vector<2> getImageDimension() const;

        /**
         * @brief Get the background color of the camera.
         *
         * @return The background color of the camera.
        */
        Color getBackgroundColor() const;

        /**
         * @brief Set the background color of the camera.
         *
         * @param color The background color of the camera.
        */
        void setBackgroundColor(const Color& color);

        /**
         * @brief Get the field of view of the camera.
         *
         * @return The field of view of the camera.
        */
        double getFov() const;

        /**
         * @brief Get the focal length of the camera.
         *
         * @return The focal length of the camera.
        */
        double getFocalLength() const;

        /**
         * @brief Get the width of the viewport.
         *
         * @return The width of the viewport.
        */
        double getViewportWidth() const;

        /**
         * @brief Get the height of the viewport.
         *
         * @return The height of the viewport.
        */
        double getViewportHeight() const;

        /**
         * @brief Get the horizontal pixel delta.
         *
         * @return The horizontal pixel delta.
        */
        Math::Vector<3> getHorizontalPixelDelta() const;

        /**
         * @brief Get the vertical pixel delta.
         *
         * @return The vertical pixel delta.
        */
        Math::Vector<3> getVerticalPixelDelta() const;

        /**
         * @brief Get the upper left corner of the viewport.
         *
         * @return The upper left corner of the viewport.
        */
        Math::Vector<3> getViewportUpperLeft() const;

        /**
         * @brief Get the position of the first pixel.
         *
         * @return The position of the first pixel.
        */
        Math::Vector<3> getFirstPixelPosition() const;

        /**
         * @brief Get the number of samples per pixel.
         *
         * @return The number of samples per pixel.
        */
        int getSamplesPerPixel() const;

        /**
         * @brief Get the value determines the scale of the pixel samples.
         *
         * @return This value determines the scale of the pixel samples.
        */
        double getPixelSampleScale() const;

        /**
         * @brief Set the number of samples per pixel.
         *
         * @param samples The number of samples per pixel.
        */
        void setSamplesPerPixel(int samples);

        /**
         * @brief Set the maximum depth of the ray.
         *
         * @param depth The maximum depth of the ray.
        */
        void setMaxDepth(int depth);

        void setImageDimension(Math::Vector<2> dimension)
        {
            _imageDimension = dimension;
        }

        /**
         * @brief Get the maximum depth of the ray.
         *
         * @return The maximum depth of the ray.
        */
        int getMaxDepth() const;

        /**
         * @brief Get the vertical field of view.
         *
         * @return The vertical field of view.
        */
        double getVfov() const;

        /**
         * @brief Set the vertical field of view.
         *
         * @param vfov The vertical field of view.
        */
        void setVfov(double vfov);

        /**
         * @brief Get the look from vector.
         *
         * @return The look from vector.
        */
        Math::Vector<3> getLookFrom() const;

        /**
         * @brief Set the look from vector.
         *
         * @param lookfrom The look from vector.
        */
        void setLookFrom(const Math::Vector<3>& lookfrom);

        /**
         * @brief Get the look at vector.
         *
         * @return The look at vector.
        */
        Math::Vector<3> getLookAt() const;

        /**
         * @brief Set the look at vector.
         *
         * @param lookat The look at vector.
        */
        void setLookAt(const Math::Vector<3>& lookat);

        /**
         * @brief Get the view up vector.
         *
         * @return The view up vector.
        */
        Math::Vector<3> getVup() const;

        /**
         * @brief Set the view up vector.
         *
         * @param vup The view up vector.
        */
        void setVup(const Math::Vector<3>& vup);

        /**
         * @brief Get the horizontal vector.
         *
         * @return The horizontal vector.
        */
        Math::Vector<3> getU() const;

        /**
         * @brief Set the horizontal vector.
         *
         *  @param u The horizontal vector.
        */
        void setU(const Math::Vector<3>& u);

        /**
         * @brief Get the vertical vector.
         *
         * @return The vertical vector.
        */
        Math::Vector<3> getV() const;

        /**
         * @brief Set the vertical vector.
         *
         * @param v The vertical vector.
        */
        void setV(const Math::Vector<3>& v);

        /**
         * @brief Get the width vector.
         *
         * @return The width vector.
        */
        Math::Vector<3> getW() const;

        /**
         * @brief Set the width vector.
         *
         * @param w The width vector.
        */
        void setW(const Math::Vector<3>& w);

        double getDefocusAngle() const;

        void setDefocusAngle(double defocusAngle);

        double getFocusDist() const;

        void setFocusDist(double focusDist);

        Math::Vector<3> defocusDiskSample() const;

        /**
         * @brief Set the filter function.
         *
         * @param filter The filter function.
        */
        void setFilter(std::function<Color(Color)> filter);

        /**
         * @brief Generate a ray from the camera based on the given coordinates.
         *
         * @param ray The ray to generate.
         * @param world The world to render.
         * @return The color of the ray.
        */
        Color rayColor(const Ray& ray, int depth, const APrimitive& world) const;

        Ray getRay(int i, int j, int sample) const;

        void print(void) noexcept
        {
            std::cout << "Camera:" << std::endl;
            std::cout << "\tImageDimension=" << _imageDimension << std::endl;
            std::cout << "\tPosition(setLookFrom)=" << getLookFrom() << std::endl;
            std::cout << "\tPosition(setLookAt)=" << getLookAt() << std::endl;
            std::cout << "\tgetVfov=" << getVfov() << std::endl;
            std::cout << "\tgetVup=" << getVup() << std::endl;
            std::cout << "\tMaxDeph=" << getMaxDepth() << std::endl;
            std::cout << "\tViewportWidth=" << _viewportWidth << std::endl;
            std::cout << "\tLightEnabled=" << _lightEnabled << std::endl;
            std::cout << "\tBackgroundColor=" << _backgroundColor.red << _backgroundColor.green << _backgroundColor.blue << std::endl;
        }
        void setLightEnabled(bool enabled);

        [[nodiscard]] bool getLightEnable(void)
        {
            return _lightEnabled;
        }

        bool isLightEnabled() const;

    protected:
        Math::Vector<3> sampleSquare(int sample) const;

        Math::Vector<3> randomInUnitSphere() const;

        Math::Vector<3> randomOnHemisphere(const Math::Vector<3> &normal) const;

        /**
        * @brief The viewport of the camera.
        *
        * This rectangle defines the area of the 3D scene that the camera can see.
        */
        Math::Rectangle _viewport;

        /**
         * @brief The dimension of the output image.
         *
         * This value determines the width and height of the image.
        */
        Math::Vector<2> _imageDimension;

        /**
         * @brief The background color of the camera.
         *
         * This value determines the color of the background when no object is hit by the ray.
        */
        Color _backgroundColor;

        /**
        * @brief The field of view of the camera.
        *
        * This value determines the angle of the camera's view cone.
        */
        double _fov;

        /**
         * @brief The focal length of the camera.
         *
         * This value determines the distance between the camera and the focal point.
        */
        double _focalLength;

        /**
         * @brief The width of the viewport.
         *
         * This value determines the width of the camera's view.
        */
        double _viewportWidth;

        /**
         * @brief The height of the viewport.
         *
         * This value determines the height of the camera's view.
        */
        double _viewportHeight;

        /**
         * @brief The delta between horizontal pixels.
         *
         * This value determines the horizontal distance between each pixel.
        */
        Math::Vector<3> _horizontalPixelDelta;

        /**
         * @brief The delta between vertical pixels.
         *
         * This value determines the vertical distance between each pixel.
        */
        Math::Vector<3> _verticalPixelDelta;

        /**
         * @brief The upper left corner of the viewport.
         *
         * This value determines the position of the upper left corner of the viewport.
        */
        Math::Vector<3> _viewportUpperLeft;

        /**
         * @brief The position of the upper left pixel.
         *
         * This value determines the position of the upper left pixel.
        */
        Math::Vector<3> _firstPixelPosition;

        /**
         * @brief The number of samples per pixel.
         *
         * This value determines the number of samples to take per pixel.
        */
        int _samplesPerPixel;

        /**
         * @brief The scale of the pixel samples.
         *
         * This value determines the scale of the pixel samples.
        */
        double _pixelSamplesScale;

        /**
         * @brief The maximum depth of the ray.
         *
         * This value determines the maximum depth of the ray.
        */
        int maxDepth;

        /**
         * @brief The vertical field of view.
         *
         * This value determines the vertical field of view.
        */
        double _vfov;

        /**
         * @brief The look from vector.
         *
         * This value determines the look from vector.
        */
        Math::Vector<3> _lookfrom = Math::Vector<3>({-2, 2, 1});

        /**
         * @brief The look at vector.
         *
         * This value determines the look at vector.
        */
        Math::Vector<3> _lookat = Math::Vector<3>({0, 0, -1});

        /**
         * @brief The view up vector.
         *
         * This value determines the view up vector.
        */
        Math::Vector<3> _vup = Math::Vector<3>({0, 1, 0});

        /**
         * @brief The horizontal vector.
         *
         * This value determines the horizontal vector.
        */
        Math::Vector<3> _u;

        /**
         * @brief The vertical vector.
         *
         * This value determines the vertical vector.
        */
        Math::Vector<3> _v;

        /**
         * @brief The width vector.
         *
         * This value determines the width vector.
        */
        Math::Vector<3> _w;

        double _defocusAngle;

        double _focusDist;

        Math::Vector<3> defocusDiskU;

        Math::Vector<3> defocusDiskV;

        sf::Uint8 *_pixels;

        bool _rendered;

        bool _showAth;

        bool _lightEnabled;


        /**
        * @brief A function that applies a filter to the color of the ray.
        *
        * This function is used to modify the color of the ray before it is returned.
        */
        std::function<Color(Color)> _filter;
};
