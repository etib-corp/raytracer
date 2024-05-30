/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** RaytracerAddPanel
*/

#include "RaytracerAth/RaytracerAddPanel.hpp"

RaytracerAddPanel::RaytracerAddPanel()
{
    this->_title = "Configure your primitive";

    std::vector<std::string> shapesNames = {
        "Sphere", "Cylinder", "Cone"
    };
    this->_shapes = new GUI::RadioButtonList("Shapes list", shapesNames);
    this->_shapes->setDisplay(true);

    std::vector<std::string> materialsNames = {
        "Dielectric", "Lambertian", "Metal"
    };
    this->_materials = new GUI::RadioButtonList("Materials list", materialsNames);
    this->_materials->setDisplay(true);

    this->_textureConf = new GUI::ChildPanel("Configure the material's texture");
    this->_textureConf->setDisplay(true);

    this->_color = new GUI::EditColor();
    this->_color->setDisplay(true);

    this->_textureConf->addInteractive(*this->_color);

    this->_checker = new GUI::RadioButton("Checker");
    this->_checker->setDisplay(true);

    this->_textureConf->addInteractive(*this->_checker);

    this->_createButton = new GUI::Button("Create",
        [&] {
            this->setDisplay(false);
            std::shared_ptr<ITexture> texture;
            Color color = Color(this->_color->getX(), this->_color->getY(), this->_color->getZ());
            Color defaultColor = Color(1, 1, 1);
            if (this->_checker->isActive()) {
                texture = std::make_shared<Checker>(1, color, defaultColor);
            } else {
                texture = std::make_shared<SolidColor>(color);
            }
            std::shared_ptr<IMaterial> material;
            std::string materialChecked = this->_materials->getChecked();

            if (materialChecked == "Dielectric") {
                material = std::make_shared<Dielectric>(1.5);
            } else if (materialChecked == "Lambertian") {
                material = std::make_shared<Lambertian>(texture);
            } else if (materialChecked == "Metal") {
                material = std::make_shared<Metal>(color);
            } else {
                material = std::make_shared<Lambertian>(texture);
            }

            std::string shapeChecked = this->_shapes->getChecked();

            if (shapeChecked == "Sphere") {
                this->_world->add(std::make_shared<Sphere>(Math::Vector<3>({0,0,0}), 1, material));
            } else if (shapeChecked == "Cone") {
                this->_world->add(std::make_shared<Cone>(Math::Vector<3>(), 2, 1, material));
            } else if (shapeChecked == "Cylinder") {
                this->_world->add(std::make_shared<Cylindre>(Math::Vector<3>(), 2, 1, material));
            } else {
                this->_world->add(std::make_shared<Sphere>(Math::Vector<3>({0,0,0}), 1, material));
            }
        }
    );
    this->_createButton->setDisplay(true);

    this->addInteractive(*this->_shapes);
    this->addInteractive(*this->_materials);
    this->addInteractive(*this->_textureConf);
    this->addInteractive(*this->_createButton);
}

void RaytracerAddPanel::init(sf::RenderWindow &window, sf::Clock &clock, ObjectsList &world)
{
    this->_window = &window;
    this->_clock = &clock;
    this->_world = &world;
    this->_shapes->init(*this->_window, *this->_clock, *this->_world);
    this->_materials->init(*this->_window, *this->_clock, *this->_world);
    this->_textureConf->init(*this->_window, *this->_clock, *this->_world);
    this->_color->init(*this->_window, *this->_clock, *this->_world);
    this->_checker->init(*this->_window, *this->_clock, *this->_world);
    this->_createButton->init(*this->_window, *this->_clock, *this->_world);
}
