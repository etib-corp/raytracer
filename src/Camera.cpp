/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Camera
*/

#include "Camera.hpp"

Camera::Camera(void) : _filter([](Color c) { return c; })
{
}

void Camera::setCamera(void)
{
    const Math::Vector<2>& imageDimension = getImageDimension();
    this->_position = this->_lookfrom;
    this->_imageDimension = imageDimension;
    this->_focalLength = (this->_lookfrom - this->_lookat).length();
    this->_vfov = getVfov();
    double theta = degrees_to_radians(this->_vfov);
    double h = tan(theta / 2.0);
    this->_focusDist = 10.0;
    this->_defocusAngle = 0.0;
    this->_viewportHeight = 2.0 * h * this->_focusDist;
    this->_viewportWidth = this->_viewportHeight * (imageDimension[0] / imageDimension[1]);

    this->_w = (this->_lookfrom - this->_lookat).unit_vector();
    this->_u = this->_vup.cross(this->_w).unit_vector();
    this->_v = this->_w.cross(this->_u);

    this->_viewport = Math::Rectangle(
        this->_position,
        this->_u * this->_viewportWidth,
        this->_v * -1.0 * this->_viewportHeight
    );
    this->_horizontalPixelDelta = this->_viewport.getTopSide() / imageDimension[0];
    this->_verticalPixelDelta = this->_viewport.getLeftSide() / imageDimension[1];
    this->_viewportUpperLeft = this->_position - (this->_w * this->_focusDist) - this->_viewport.getTopSide() / 2 - this->_viewport.getLeftSide() / 2;
    this->_firstPixelPosition = this->_viewportUpperLeft + (this->_horizontalPixelDelta + this->_verticalPixelDelta) * 0.5;
    this->_samplesPerPixel = getSamplesPerPixel();
    this->_pixelSamplesScale = 1.0 / this->_samplesPerPixel;
    this->maxDepth = 50;
    double defocusRadius = this->_focusDist * tan(degrees_to_radians(this->_defocusAngle) / 2.0);
    this->defocusDiskU = this->_u * defocusRadius;
    this->defocusDiskV = this->_v * defocusRadius;
    this->_pixels = new sf::Uint8[static_cast<int>(this->_imageDimension[0]) * static_cast<int>(this->_imageDimension[1]) * 4];
    for (int i = 0; i < this->_imageDimension[0] * this->_imageDimension[1] * 4; i++)
        this->_pixels[i] = 0;
    this->_rendered = false;
    this->_lightEnabled = getLightEnable();
}

Camera::Camera(const Math::Vector<2>& imageDimension) : _filter([](Color c) { return c; })
{
    std::cout << imageDimension << std::endl;
    this->_position = this->_lookfrom;
    this->_imageDimension = imageDimension;
    std::cout << "_imageDimension" << _imageDimension << std::endl;
    this->_focalLength = (this->_lookfrom - this->_lookat).length();
    this->_vfov = 20.0;
    double theta = degrees_to_radians(this->_vfov);
    double h = tan(theta / 2.0);
    this->_focusDist = 10.0;
    this->_defocusAngle = 0.0;
    this->_viewportHeight = 2.0 * h * this->_focusDist;
    this->_viewportWidth = this->_viewportHeight * (imageDimension[0] / imageDimension[1]);

    this->_w = (this->_lookfrom - this->_lookat).unit_vector();
    this->_u = this->_vup.cross(this->_w).unit_vector();
    this->_v = this->_w.cross(this->_u);

    this->_viewport = Math::Rectangle(
        this->_position,
        this->_u * this->_viewportWidth,
        this->_v * -1.0 * this->_viewportHeight
    );
    this->_horizontalPixelDelta = this->_viewport.getTopSide() / imageDimension[0];
    this->_verticalPixelDelta = this->_viewport.getLeftSide() / imageDimension[1];
    this->_viewportUpperLeft = this->_position - (this->_w * this->_focusDist) - this->_viewport.getTopSide() / 2 - this->_viewport.getLeftSide() / 2;
    this->_firstPixelPosition = this->_viewportUpperLeft + (this->_horizontalPixelDelta + this->_verticalPixelDelta) * 0.5;
    this->_samplesPerPixel = 32;
    this->_pixelSamplesScale = 1.0 / this->_samplesPerPixel;
    this->maxDepth = 50;
    double defocusRadius = this->_focusDist * tan(degrees_to_radians(this->_defocusAngle) / 2.0);
    this->defocusDiskU = this->_u * defocusRadius;
    this->defocusDiskV = this->_v * defocusRadius;
    this->_pixels = new sf::Uint8[static_cast<int>(this->_imageDimension[0]) * static_cast<int>(this->_imageDimension[1]) * 4];
    for (int i = 0; i < this->_imageDimension[0] * this->_imageDimension[1] * 4; i++)
        this->_pixels[i] = 0;
    this->_rendered = false;
    this->_lightEnabled = true;
    this->_showAth = false;
}

Camera::~Camera()
{
    // delete[] this->_pixels;
}

void Camera::init()
{
    this->_position = this->_lookfrom;
    this->_focalLength = (this->_lookfrom - this->_lookat).length();
    double theta = degrees_to_radians(this->_vfov);
    double h = tan(theta / 2.0);
    this->_viewportHeight = 2.0 * h * this->_focusDist;
    this->_viewportWidth = this->_viewportHeight * (this->_imageDimension[0] / this->_imageDimension[1]);

    this->_w = (this->_lookfrom - this->_lookat).unit_vector();
    this->_u = this->_vup.cross(this->_w).unit_vector();
    this->_v = this->_w.cross(this->_u);

    this->_viewport = Math::Rectangle(
        this->_position,
        this->_u * this->_viewportWidth,
        this->_v * -1.0 * this->_viewportHeight
    );
    this->_horizontalPixelDelta = this->_viewport.getTopSide() / this->_imageDimension[0];
    this->_verticalPixelDelta = this->_viewport.getLeftSide() / this->_imageDimension[1];
    this->_viewportUpperLeft = this->_position - (this->_w * this->_focusDist) - this->_viewport.getTopSide() / 2 - this->_viewport.getLeftSide() / 2;
    this->_firstPixelPosition = this->_viewportUpperLeft + (this->_horizontalPixelDelta + this->_verticalPixelDelta) * 0.5;
    this->_pixelSamplesScale = 1.0 / this->_samplesPerPixel;
    double defocusRadius = this->_focusDist * tan(degrees_to_radians(this->_defocusAngle) / 2.0);
    this->defocusDiskU = this->_u * defocusRadius;
    this->defocusDiskV = this->_v * defocusRadius;
}

Ray Camera::ray(double u, double v) const
{
    double x = u / this->_imageDimension[0] - 0.5;
    double angle = atan2(x, this->_focalLength);
    return Ray(this->_position, Math::Vector<3>(this->_viewport.pointAt(u, v) - this->_position));
}

std::chrono::_V2::system_clock::time_point Camera::render(const APrimitive& world)
{
    this->init();
    int width = this->_imageDimension[0];
    int height = this->_imageDimension[1];
    int linesRemaining = this->_imageDimension[1];
    int threadRemaining = this->_imageDimension[1];
    std::clog << "\r                                             " << std::flush;
    std::clog << "\rLines remaining: " << linesRemaining <<    std::flush;
    auto start = std::chrono::high_resolution_clock::now();
    std::function<void *(int, int)> function = [&] (int start, int end) {
        std::vector<std::thread> threads;
        for (int j = start; j < end; j++) {
            for (int i = 0; i < width; i++) {
                threads.emplace_back(std::thread([&] () {
                    Color pixel(0, 0, 0);
                    for (int sample = 0; sample < this->_samplesPerPixel; sample++) {
                        Ray ray = this->getRay(i, j, sample);
                        pixel = pixel + this->rayColor(ray, this->maxDepth, world);
                    }
                    pixel = pixel * this->_pixelSamplesScale;
                    this->_pixels[(j * static_cast<int>(width) + i) * 4 + 0] = pixel.red * 255;
                    this->_pixels[(j * static_cast<int>(width) + i) * 4 + 1] = pixel.green * 255;
                    this->_pixels[(j * static_cast<int>(width) + i) * 4 + 2] = pixel.blue * 255;
                    this->_pixels[(j * static_cast<int>(width) + i) * 4 + 3] = pixel.alpha * 255;
                }));
                for (auto& thread : threads)
                    thread.join();
                threads.clear();
            }
            std::clog << "\r                                             " << std::flush;
            std::clog << "\rLines remaining: " << --linesRemaining << std::flush;
            if (linesRemaining == 0) {
                this->_rendered = true;
            }
        }
        return nullptr;
    };

    std::thread renderThread = std::thread([&]() {
        std::vector<std::thread> threads(height);
        int segmentSize = height / height;

        for (int i = 0; i < height; ++i) {
            int start = i * segmentSize;
            int end = (i == height - 1) ? height : start + segmentSize; // Handle the last segment possibly taking the remaining part
            threads[i] = std::thread([=] { function(start, end); });
        }

        for (std::thread &th : threads) {
            th.join();
        }

    });
    renderThread.join();
    return start;
}

bool Camera::checkMove(sf::Event event)
{
    bool moved = false;
    Math::Vector<3> direction = (this->_lookfrom - this->_lookat).unit_vector();
    Math::Vector<3> right = this->_vup.cross(direction).unit_vector();

    if (event.key.code == sf::Keyboard::W) {
        moved = true;
        this->_lookfrom[2] -= 0.5 * direction[2];
        this->_lookat[2] -= 0.5 * direction[2];
    }
    if (event.key.code == sf::Keyboard::S) {
        moved = true;
        this->_lookfrom[2] += 0.5 * direction[2];
        this->_lookat[2] += 0.5 * direction[2];
    }
    if (event.key.code == sf::Keyboard::A) {
        moved = true;
        this->_lookfrom[0] -= 0.5 * right[0];
        this->_lookat[0] -= 0.5 * right[0];
    }
    if (event.key.code == sf::Keyboard::D) {
        moved = true;
        this->_lookfrom[0] += 0.5 * right[0];
        this->_lookat[0] += 0.5 * right[0];
    }
    if (event.key.code == sf::Keyboard::Q) {
        moved = true;
        this->_lookfrom[1] -= 0.5;
        this->_lookat[1] -= 0.5;
    }
    if (event.key.code == sf::Keyboard::E) {
        moved = true;
        this->_lookfrom[1] += 0.5;
        this->_lookat[1] += 0.5;
    }
    if (event.key.code == sf::Keyboard::Up) {
        moved = true;
        this->_lookat[1] += 0.5;
    }
    if (event.key.code == sf::Keyboard::Down) {
        moved = true;
        this->_lookat[1] -= 0.5;
    }
    if (event.key.code == sf::Keyboard::Left) {
        moved = true;
        this->_lookat[0] -= 0.5;
        this->_lookat[2] += 0.5;
    }
    if (event.key.code == sf::Keyboard::Right) {
        moved = true;
        this->_lookat[0] += 0.5;
        this->_lookat[2] -= 0.5;
    }
    if (event.MouseButtonPressed == sf::Event::MouseButtonPressed) {
        moved = true;
    }
    if (moved) {
        delete[] this->_pixels;
        this->_imageDimension = Math::Vector<2>({WIDTH, HEIGHT});
        this->_pixels = new sf::Uint8[static_cast<int>(this->_imageDimension[0]) * static_cast<int>(this->_imageDimension[1]) * 4];
    }
    return moved;
}

void Camera::renderSFML(ObjectsList& world)
{
    sf::Sprite sprite;
    sf::Texture texture;
    texture.create(this->_imageDimension[0], this->_imageDimension[1]);
    sprite.setTexture(texture);
    int linesRemaining = this->_imageDimension[1];
    int threadRemaining = this->_imageDimension[1];
    int width = this->_imageDimension[0];
    int height = this->_imageDimension[1];
    auto start = this->render(world);

    sf::RenderWindow window(sf::VideoMode(width, height), "Raytracer");
    window.setFramerateLimit(60);

    ImGui::SFML::Init(window);
    sf::Clock clock;
    RaytracerATH *ath = new RaytracerATH();
    ath->init(window, clock, world);
    while (window.isOpen()) {
        sf::Event event;
        if (this->_rendered) {
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            std::cout << "\nRendered in " << elapsed.count() << "s" << std::endl;
            this->_rendered = false;
        }
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed) {
                window.close();
                exit(0);
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                start = this->render(world);
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                    exit(0);
                }
                if (event.key.code == sf::Keyboard::R) {
                    this->_imageDimension = Math::Vector<2>({RENDER_WIDTH, RENDER_HEIGHT});
                    delete[] this->_pixels;
                    this->_pixels = new sf::Uint8[static_cast<int>(this->_imageDimension[0]) * static_cast<int>(this->_imageDimension[1]) * 4];
                    this->_samplesPerPixel = 1024;
                    window.close();
                    this->_showAth = false;
                    return this->renderSFML(world);
                    this->_imageDimension = Math::Vector<2>({2000, 2000 / ASPECT_RATIO});
                }
                if (event.key.code == sf::Keyboard::F) {
                    // TODO could ask for a filename in an ImGui window
                    // ! precising that it only support bmp, png, tga and jpg
                    texture.copyToImage().saveToFile("raytracer.png");
                    std::cout << "Export done to raytracer.png" << std::endl;
                }
                if (this->checkMove(event)) {
                    if (texture.getSize().x != this->_imageDimension[0]) {
                        texture.create(this->_imageDimension[0], this->_imageDimension[1]);
                        sprite.setTexture(texture);
                        this->_samplesPerPixel = 32;
                        window.close();
                        this->_showAth = false;
                        return this->renderSFML(world);
                    }
                    this->_showAth = true;
                    start = this->render(world);
                }
            }
        }

        ImGui::SFML::Update(window, clock.restart());
        window.clear();
        if (this->_showAth) {
            ath->update();
            ath->display();
        }
        texture.update(this->_pixels);
        window.draw(sprite);
        ImGui::SFML::Render(window);
        window.display();
    }
}

Math::Rectangle Camera::getViewport() const
{
    return this->_viewport;
}

Math::Vector<2> Camera::getImageDimension() const
{
    return this->_imageDimension;
}

Color Camera::getBackgroundColor() const
{
    return this->_backgroundColor;
}

void Camera::setBackgroundColor(const Color& color)
{
    this->_backgroundColor = color;
}

double Camera::getFov() const
{
    return this->_fov;
}

double Camera::getFocalLength() const
{
    return this->_focalLength;
}

double Camera::getViewportHeight() const
{
    return this->_viewportHeight;
}

double Camera::getViewportWidth() const
{
    return this->_viewportWidth;
}

Math::Vector<3> Camera::getHorizontalPixelDelta() const
{
    return this->_horizontalPixelDelta;
}

Math::Vector<3> Camera::getVerticalPixelDelta() const
{
    return this->_verticalPixelDelta;
}

Math::Vector<3> Camera::getViewportUpperLeft() const
{
    return this->_viewportUpperLeft;
}

Math::Vector<3> Camera::getFirstPixelPosition() const
{
    return this->_firstPixelPosition;
}

int Camera::getMaxDepth() const
{
    return this->maxDepth;
}

int Camera::getSamplesPerPixel() const
{
    return this->_samplesPerPixel;
}

void Camera::setSamplesPerPixel(int samples)
{
    this->_samplesPerPixel = samples;
}

double Camera::getPixelSampleScale() const
{
    return this->_pixelSamplesScale;
}

double Camera::getVfov() const
{
    return this->_vfov;
}

void Camera::setVfov(double vfov)
{
    this->_vfov = vfov;
}

Math::Vector<3> Camera::getLookFrom() const
{
    return this->_lookfrom;
}

void Camera::setLookFrom(const Math::Vector<3>& lookfrom)
{
    this->_lookfrom = lookfrom;
}

Math::Vector<3> Camera::getLookAt() const
{
    return this->_lookat;
}

void Camera::setLookAt(const Math::Vector<3>& lookat)
{
    this->_lookat = lookat;
}

Math::Vector<3> Camera::getVup() const
{
    return this->_vup;
}

void Camera::setVup(const Math::Vector<3>& vup)
{
    this->_vup = vup;
}

Color Camera::rayColor(const Ray& ray, int depth, const APrimitive& world) const
{
    if (depth <= 0)
        return Color(0, 0, 0);
    HitRecord rec;
    Ray scattered;
    Color attenuation;
    if (this->_lightEnabled) {
        if (!world.hit(ray, Interval(0.001, infinity), rec))
            return this->_filter(this->getBackgroundColor());
        Color emission = rec.material->emitted(ray, rec, rec.u, rec.v, rec.point);
        if (!rec.material->scatter(ray, rec, attenuation, scattered))
            return emission;
        Color scatter = attenuation * this->rayColor(scattered, depth - 1, world);
        return emission + scatter;
    } else {
        if (world.hit(ray, Interval(0.001, infinity), rec)) {
            if (rec.material != nullptr && rec.material->scatter(ray, rec, attenuation, scattered))
                return this->_filter(attenuation * this->rayColor(scattered, depth - 1, world));
            return this->_filter(Color(0, 0, 0));
        }
        Math::Vector<3> unit_direction = ray.getDirection().normalize();
        double a = 0.5 * (unit_direction[1] + 1.0);
        Color pixel = Color(1.0, 1.0, 1.0) * (1.0 - a) + Color(0.5, 0.7, 1.0) * a;
        return this->_filter(pixel);
    }
}

inline Ray Camera::getRay(int i, int j, int sample) const
{
    Math::Vector<3> offset = this->sampleSquare(sample);
    Math::Vector<3> center = this->_firstPixelPosition + (this->_horizontalPixelDelta * (i + offset[0])) + (this->_verticalPixelDelta * (j + offset[1]));
    Math::Vector<3> rayOrigin = this->_position;
    Ray ray(this->_position, center - rayOrigin);
    return ray;
}

void Camera::setLightEnabled(bool enabled)
{
    this->_lightEnabled = enabled;
}

bool Camera::isLightEnabled() const
{
    return this->_lightEnabled;
}

Math::Vector<3> Camera::sampleSquare(int sample) const
{
    int samples = this->_samplesPerPixel;
    int squareRoot = std::sqrt(samples);

    if (squareRoot & (squareRoot - 1) == 0) {
        int n = squareRoot;
        asm("bsr %1, %0" : "=r" (n) : "r" (n));
        return Math::Vector<3>({(this->_pixelSamplesScale) + (1.0 / squareRoot) * (squareRoot - 1), (this->_pixelSamplesScale) + (1.0 / squareRoot) * (sample >> n), 0.0});
    }
    return Math::Vector<3>({(this->_pixelSamplesScale) + (1.0 / squareRoot) * (sample % squareRoot), (this->_pixelSamplesScale) + (1.0 / squareRoot) * (sample / squareRoot), 0.0});
}

Math::Vector<3> Camera::randomInUnitSphere() const
{
    while (true) {
        Math::Vector<3> v = Math::Vector<3>::random(-1.0, 1.0);
        if (v.length_squared() < 1)
            return v;
    }
}

Math::Vector<3> Camera::randomOnHemisphere(const Math::Vector<3> &normal) const
{
    Math::Vector<3> inUnitSphere = randomInUnitSphere().unit_vector();
    if (inUnitSphere.dot(normal) > 0.0)
        return inUnitSphere;
    else
        return inUnitSphere * -1.0;
}

Math::Vector<3> Camera::getU() const
{
    return this->_u;
}

void Camera::setU(const Math::Vector<3>& u)
{
    this->_u = u;
}

Math::Vector<3> Camera::getV() const
{
    return this->_v;
}

void Camera::setV(const Math::Vector<3>& v)
{
    this->_v = v;
}

Math::Vector<3> Camera::getW() const
{
    return this->_w;
}

void Camera::setW(const Math::Vector<3>& w)
{
    this->_w = w;
}

void Camera::setMaxDepth(int depth)
{
    this->maxDepth = depth;
}

void Camera::setFilter(std::function<Color(Color)> filter)
{
    this->_filter = filter;
}


double Camera::getDefocusAngle() const
{
    return this->_defocusAngle;
}

void Camera::setDefocusAngle(double defocusAngle)
{
    this->_defocusAngle = defocusAngle;
}

double Camera::getFocusDist() const
{
    return this->_focusDist;
}

void Camera::setFocusDist(double focusDist)
{
    this->_focusDist = focusDist;
}

Math::Vector<3> Camera::defocusDiskSample() const
{
    Math::Vector<3> disk = randomInUnitDisk();
    return this->_position + (this->defocusDiskU * disk[0]) + (this->defocusDiskV * disk[1]);
}
