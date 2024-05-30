/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** MaterialPanel
*/

#include "RaytracerAth/MaterialPanel.hpp"

MaterialPanel::MaterialPanel()
{
    this->_color = new GUI::EditColor();
    this->_color->setDisplay(true);
    this->_material = nullptr;
}

MaterialPanel::MaterialPanel(std::shared_ptr<IMaterial> material)
{
    this->_material = material;
    this->_color = new GUI::EditColor();
    this->_color->setDisplay(true);
    this->_index = new GUI::DoubleInput("Index");

    switch (this->_material->getType()) {
        case IMaterial::Type::LAMBERTIAN:
            break;
        case IMaterial::Type::METAL:
            this->_index->setDisplay(true);
            break;
        case IMaterial::Type::DIELECTRIC:
            this->_index->setDisplay(true);
            break;
        default:
            break;
    }
}

void MaterialPanel::init(sf::RenderWindow &window, sf::Clock &clock, ObjectsList &world)
{
    this->_window = &window;
    this->_clock = &clock;
    this->_world = &world;
    this->_index->init(window, clock, world);
    this->_color->init(window, clock, world);
}

void MaterialPanel::display()
{
    if (!this->hasToDisplay()) {
        return;
    }

    Color color = this->_material->getAlbedo();
    this->_color->setX(color.red);
    this->_color->setY(color.green);
    this->_color->setZ(color.blue);
    ImGui::BeginListBox("Material");
    this->_color->display();
    switch (this->_material->getType()) {
        case IMaterial::Type::LAMBERTIAN:
            this->_index->setDisplay(false);
            break;
        case IMaterial::Type::METAL:
            this->_index->setValue(dynamic_cast<Metal *>(this->_material.get())->getFuzz());
            this->_index->setDisplay(true);
            this->_index->setTitle("Fuzz");
            this->_index->display();
            break;
        case IMaterial::Type::DIELECTRIC:
            this->_index->setValue(dynamic_cast<Dielectric *>(this->_material.get())->getRefractiveIndex());
            this->_index->setDisplay(true);
            this->_index->setTitle("Refractive index");
            this->_index->display();
            break;
        default:
            break;
    }
    ImGui::EndListBox();
    color = Color(this->_color->getX(), this->_color->getY(), this->_color->getZ());
    this->_material->setAlbedo(color);
    switch (this->_material->getType()) {
        case IMaterial::Type::LAMBERTIAN:
            break;
        case IMaterial::Type::METAL:
            dynamic_cast<Metal *>(this->_material.get())->setFuzz(this->_index->getValue());
            break;
        case IMaterial::Type::DIELECTRIC:
            dynamic_cast<Dielectric *>(this->_material.get())->setRefractiveIndex(this->_index->getValue());
            break;
        default:
            break;
    }

}

void MaterialPanel::setMaterial(std::shared_ptr<IMaterial> material)
{
    this->_material = material;
}
