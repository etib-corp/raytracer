/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** RaytracerAth
*/

#include "RaytracerAth/RaytracerAth.hpp"

void RaytracerATH::createMainPanel()
{
    GUI::Panel *panel = new GUI::Panel("Scene viewer");
    panel->init(*this->_window, *this->_clock, *this->_world);
    panel->setDisplay(true);
    GUI::Button *button = new GUI::Button("+ Add a Primitive",
    [&] {
        this->_addPanel->setDisplay(true);
        this->_confPanel->setDisplay(false);
    });
    button->init(*this->_window, *this->_clock, *this->_world);
    button->setDisplay(true);

    GUI::ScrollableChild *list = new GUI::ScrollableChild("Elements in scene");
    list->init(*this->_window, *this->_clock, *this->_world);
    list->setDisplay(true);

    for (auto i = 0; i < this->_world->_objects.size(); i++) {
        std::string name;
        switch (this->_world->_objects.at(i)->getType()) {
            case APrimitive::Type::CYLINDER:
                name = "Cylinder";
                break;
            case APrimitive::Type::DISK:
                name = "Disk";
                break;
            case APrimitive::Type::CONE:
                name = "Cone";
                break;
            case APrimitive::Type::SPHERE:
                name = "Sphere";
                break;
            case APrimitive::Type::PLANE:
                name = "Plane";
                break;
            default:
                name = "Shape";
                break;
        }
        GUI::Button *tmp = new GUI::Button(std::to_string(i) + " Edit " + name, [=] {
            this->setIndex(i);
            this->_confPanel->setDisplay(true);
            this->_addPanel->setDisplay(false);
        });
        tmp->init(*this->_window, *this->_clock, *this->_world);
        tmp->setDisplay(true);
        list->addInteractive(*tmp);
    }
    panel->addInteractive(*button);
    panel->addInteractive(*list);
    this->_mainPanel = panel;
}

RaytracerATH::RaytracerATH()
{
    this->_addPanel = new RaytracerAddPanel();
    this->_confPanel = new RaytracerConfigPanel();
    this->_toolBar = new GUI::ToolBar();
    std::map<std::string, std::function<void()>> file;
    file["New"] = [this] {
        this->_world->clear();
        this->_index = 0;
        this->_render = true;
    };
    file["Open"] = [this] {
        this->_world->clear();
        this->_index = 0;
        this->_render = true;
    };
    file["Save"] = [this] {
        this->_world->clear();
        this->_index = 0;
    };
    file["Quit"] = [this] {
        exit(0);
    };
    std::map<std::string, std::function<void()>> edit;
    edit["Delete"] = [this] {
        std::cout << "WIP" << std::endl;
    };
    std::map<std::string, std::function<void()>> help;
    help["Add shapes"] = [this] {
        ImGui::MenuItem("Just click on '+ Add Shape'");
    };
    this->_toolBar->setFileFunctions(file);
    this->_toolBar->setEditFunctions(edit);
    this->_toolBar->setHelpFunctions(help);
    this->_index = 0;
}

void RaytracerATH::init(sf::RenderWindow &window, sf::Clock &clock, ObjectsList &world)
{
    this->_window = &window;
    this->_clock = &clock;
    this->_world = &world;
    this->setDisplay(true);
    this->_addPanel->init(window, clock, world);
    this->_confPanel->init(window, clock, world);
    this->createMainPanel();
}

void RaytracerATH::update()
{
    this->createMainPanel();
}

void RaytracerATH::display()
{
    if (this->hasToDisplay()) {
        this->_confPanel->setObject(this->_world->_objects[this->_index]);
        this->_mainPanel->display();
        // this->_controlPanel->display();
        this->_toolBar->display();
        this->_addPanel->display();
        this->_confPanel->display();
    }
}
