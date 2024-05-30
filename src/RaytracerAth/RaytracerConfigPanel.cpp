/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** RaytracerConfigPanel
*/

#include "RaytracerAth/RaytracerConfigPanel.hpp"

RaytracerConfigPanel::RaytracerConfigPanel()
{
}

void RaytracerConfigPanel::init(sf::RenderWindow &window, sf::Clock &clock, ObjectsList &world)
{
    this->_window = &window;
    this->_clock = &clock;
    this->_world = &world;
    this->_object = this->_world->_objects.size() == 0 ? nullptr : this->_world->_objects.at(0);
    this->_transform = new TransformPanel(this->_object);
    this->_material = new MaterialPanel(this->_object->getMaterial());
    switch (this->_object->getMaterial()->getType()) {
        case IMaterial::LAMBERTIAN:
            this->_texture = new TexturePanel(dynamic_cast<Lambertian *>(this->_object->getMaterial().get())->getTexture());
            break;
        default:
            this->_texture = nullptr;
            break;
    }
    this->_transform->setDisplay(true);
    this->_material->setDisplay(true);
    if (this->_texture != nullptr)
        this->_texture->setDisplay(true);
}

void RaytracerConfigPanel::setObject(std::shared_ptr<APrimitive> object)
{
    this->_object = object;
    this->_transform->setObject(this->_object);
    this->_material->setMaterial(this->_object->getMaterial());
    switch (this->_object->getMaterial()->getType()) {
        case IMaterial::LAMBERTIAN:
            this->_texture->setTexture(dynamic_cast<Lambertian *>(this->_object->getMaterial().get())->getTexture());
            break;
        default:
            break;
    }
}

void RaytracerConfigPanel::display()
{
    if (this->_object == nullptr || !this->hasToDisplay())
        return;
    switch (this->_object->getType()) {
        case APrimitive::Type::CYLINDER:
            this->_name = "Cylinder";
            break;
        case APrimitive::Type::DISK:
            this->_name = "Disk";
            break;
        case APrimitive::Type::CONE:
            this->_name = "Cone";
            break;
        case APrimitive::Type::SPHERE:
            this->_name = "Sphere";
            break;
        case APrimitive::Type::PLANE:
            this->_name = "Plane";
            break;
        default:
            this->_name = "Shape";
            break;
    }

    std::string title = "Configure your " + this->_name;
    ImGui::Begin(title.c_str());
    this->_transform->display();
    this->_material->display();
    if (this->_texture != nullptr)
        this->_texture->display();
    ImGui::End();
}
