/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** RadioButtonList
*/

#include "GUI/RadioButtonList.hpp"

GUI::RadioButtonList::RadioButtonList(std::string title, std::vector<std::string> titles)
{
    this->_title = title;
    for (auto &name : titles) {
        RadioButton *radio = new RadioButton(name);

        this->_children.push_back(radio);
    }
}

void GUI::RadioButtonList::init(sf::RenderWindow &window, sf::Clock &clock, ObjectsList &world)
{
    this->_window = &window;
    this->_clock = &clock;
    this->_world = &world;

    for (auto &button : this->_children) {
        button->init(*this->_window, *this->_clock, *this->_world);
        button->setDisplay(true);
    }
    this->_lastChecked = this->_children.end();
}

void GUI::RadioButtonList::display()
{
    this->update();
    if (this->hasToDisplay()) {
        ImGui::BeginListBox(this->_title.c_str());
        for (auto &button : this->_children)
            button->display();
        ImGui::EndListBox();
    }
}

void GUI::RadioButtonList::update()
{
    for (auto it = this->_children.begin(); it != this->_children.end(); it++) {
        if ((*it)->isActive() && it != this->_lastChecked) {
            if (this->_lastChecked != this->_children.end())
                (*this->_lastChecked)->setActive(false);
            this->_lastChecked = it;
        }
    }
}

std::string GUI::RadioButtonList::getChecked() const
{
    if (this->_lastChecked!= this->_children.end())
        return (*this->_lastChecked)->getTitle();
    return "";
}
