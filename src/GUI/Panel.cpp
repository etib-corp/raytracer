/*
** EPITECH PROJECT, 2024
** '
** File description:
** Panel
*/

#include "GUI/Panel.hpp"

GUI::Panel::Panel()
{
    this->_title = "Panel";
}

GUI::Panel::Panel(const std::string &title)
{
    this->_title = title;
}

void GUI::Panel::addInteractive(GUI::AInteractive &interactive)
{
    this->_children.push_back(&interactive);
}

void GUI::Panel::display()
{
    if (this->hasToDisplay()) {
        ImGui::Begin(this->_title.c_str());
        for (auto &elm : this->_children)
            elm->display();
        ImGui::End();
    }
}
