/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** ScrollableChild
*/

#include "GUI/ScrollableChild.hpp"

GUI::ScrollableChild::ScrollableChild(const std::string &title)
{
    this->_title = title;
}

void GUI::ScrollableChild::display()
{
    if (this->hasToDisplay()) {
        ImGui::BeginChild(this->_title.c_str(), ImVec2(0, 0), true, ImGuiWindowFlags_AlwaysVerticalScrollbar);
        for (auto &elm : this->_children)
            elm->display();
        ImGui::EndChild();
    }
}
