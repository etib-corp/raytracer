/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** ChildPanel
*/

#include "GUI/ChildPanel.hpp"

GUI::ChildPanel::ChildPanel()
{
    this->_title = "ChildPanel";
}

GUI::ChildPanel::ChildPanel(const std::string &title)
{
    this->_title = title;
}

void GUI::ChildPanel::display()
{
    if (this->hasToDisplay()) {
        ImGui::BeginListBox(this->_title.c_str());
        for (auto &elm : this->_children)
            elm->display();
        ImGui::EndListBox();
    }
}

void GUI::ChildPanel::addInteractive(GUI::AInteractive &element)
{
    this->_children.push_back(&element);
}

