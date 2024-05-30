/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** TransformPanel
*/

#include "RaytracerAth/TransformPanel.hpp"

TransformPanel::TransformPanel()
{
    this->_position = new GUI::EditPosition();
    this->_position->setDisplay(true);

    this->_radius = new GUI::DoubleInput("Radius");
    this->_position->setDisplay(true);

    this->_depth = new GUI::DoubleInput("Depth");
    this->_position->setDisplay(true);

    this->_object = nullptr;
}

TransformPanel::TransformPanel(std::shared_ptr<APrimitive> object)
{
    this->_object = object;
    this->_position = new GUI::EditPosition();
    this->_position->setDisplay(true);

    this->_radius = new GUI::DoubleInput("Radius");
    this->_depth = new GUI::DoubleInput("Depth");

    if (this->_object == nullptr)
        return;

    switch (this->_object->getType()) {
        case APrimitive::Type::PLANE:
            break;
        case APrimitive::Type::NONE:
            break;
        default:
            this->_radius->setDisplay(true);
            break;
    }

    switch (this->_object->getType()) {
        case APrimitive::Type::CONE:
            this->_depth->setDisplay(true);
            break;
        case APrimitive::Type::CYLINDER:
            this->_depth->setDisplay(true);
            break;
        default:
            break;
    }
}

void TransformPanel::init(sf::RenderWindow &window, sf::Clock &clock, ObjectsList &world)
{
    this->_window = &window;
    this->_clock = &clock;
    this->_world = &world;
    if (this->_object == nullptr)
        this->_object = this->_world->_objects.size() == 0 ? nullptr : this->_world->_objects.at(0);
}

void TransformPanel::display()
{
    if (this->_object == nullptr || !this->hasToDisplay()) {
        std::cout << "doesnt print" << std::endl;
        return;
    }
    this->_position->setX(this->_object->getPosition()[0]);
    this->_position->setY(this->_object->getPosition()[1]);
    this->_position->setZ(this->_object->getPosition()[2]);

    Math::Vector<3> pos;
    switch (this->_object->getType()) {
        case APrimitive::Type::CYLINDER:
            pos = dynamic_cast<Cylindre*>(this->_object.get())->getCenter();
            this->_radius->setValue(dynamic_cast<Cylindre*>(this->_object.get())->getRadius());
            this->_radius->setDisplay(true);
            this->_depth->setValue(dynamic_cast<Cylindre*>(this->_object.get())->getDepth());
            this->_depth->setDisplay(true);
            break;
        case APrimitive::Type::DISK:
            this->_radius->setValue(dynamic_cast<Disk*>(this->_object.get())->getRadius());
            this->_radius->setDisplay(true);
            this->_depth->setDisplay(false);
            break;
        case APrimitive::Type::CONE:
            pos = dynamic_cast<Cone*>(this->_object.get())->getBaseCenter();
            this->_radius->setValue(dynamic_cast<Cone*>(this->_object.get())->getRadius());
            this->_radius->setDisplay(true);
            this->_depth->setValue(dynamic_cast<Cone*>(this->_object.get())->getHeight());
            this->_depth->setDisplay(true);
            break;
        case APrimitive::Type::SPHERE:
            pos = dynamic_cast<Sphere*>(this->_object.get())->getCenter();
            this->_radius->setValue(dynamic_cast<Sphere*>(this->_object.get())->getRadius());
            this->_radius->setDisplay(true);
            this->_depth->setDisplay(false);
            break;
        default:
            pos = Math::Vector<3>();
            this->_radius->setDisplay(false);
            this->_depth->setDisplay(false);
            break;
    }
    this->_position->setX(pos[0]);
    this->_position->setY(pos[1]);
    this->_position->setZ(pos[2]);
    ImGui::BeginListBox("Transform");
    this->_position->display();
    this->_radius->display();
    this->_depth->display();
    ImGui::EndListBox();
    this->_object->setPosition(Math::Vector<3>({this->_position->getX(), this->_position->getY(), this->_position->getZ()}));
    switch (this->_object->getType()) {
        case APrimitive::Type::CYLINDER:
            dynamic_cast<Cylindre*>(this->_object.get())->setCenter(Math::Vector<3>({this->_position->getX(), this->_position->getY(), this->_position->getZ()}));
            dynamic_cast<Cylindre*>(this->_object.get())->setRadius(this->_radius->getValue());
            dynamic_cast<Cylindre*>(this->_object.get())->setDepth(this->_depth->getValue());
            break;
        case APrimitive::Type::DISK:
            dynamic_cast<Disk*>(this->_object.get())->setRadius(this->_radius->getValue());
            break;
        case APrimitive::Type::CONE:
            dynamic_cast<Cone*>(this->_object.get())->setBaseCenter(Math::Vector<3>({this->_position->getX(), this->_position->getY(), this->_position->getZ()}));
            dynamic_cast<Cone*>(this->_object.get())->setRadius(this->_radius->getValue());
            dynamic_cast<Cone*>(this->_object.get())->setHeight(this->_depth->getValue());
            break;
        case APrimitive::Type::SPHERE:
            dynamic_cast<Sphere*>(this->_object.get())->setCenter(Math::Vector<3>({this->_position->getX(), this->_position->getY(), this->_position->getZ()}));
            dynamic_cast<Sphere*>(this->_object.get())->setRadius(this->_radius->getValue());
            break;
        default:
            break;
    }
}

void TransformPanel::setObject(std::shared_ptr<APrimitive> object)
{
    this->_object = object;
}
