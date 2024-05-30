/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** AGUI
*/

#include "GUI/AGUI.hpp"

void GUI::AGUI::update()
{
    ImGui::SFML::Update(*this->_window, this->_clock->restart());
}

void GUI::AGUI::init(sf::RenderWindow &window, sf::Clock &clock, ObjectsList &world)
{
    this->_window = &window;
    this->_clock = &clock;
    this->_world = &world;
}

bool GUI::AGUI::hasToDisplay()
{
    return this->_display;
}

void GUI::AGUI::setDisplay(bool display)
{
    this->_display = display;
}

