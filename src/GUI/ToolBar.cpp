/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** ToolBar
*/

#include "GUI/ToolBar.hpp"

GUI::ToolBar::ToolBar()
{
}

GUI::ToolBar::~ToolBar()
{
}

void GUI::ToolBar::display()
{
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            for (auto f : this->_fileFunctions) {
                if (ImGui::MenuItem(f.first.c_str()))
                    f.second();
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit")) {
            for (auto f : this->_editFunctions) {
                if (ImGui::MenuItem(f.first.c_str()))
                    f.second();
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Help")) {
            for (auto f : this->_editFunctions) {
                if (ImGui::MenuItem(f.first.c_str()))
                    f.second();
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void GUI::ToolBar::setFileFunctions(std::map<std::string, std::function<void()>> fileFunctions)
{
    this->_fileFunctions = fileFunctions;
}

void GUI::ToolBar::setEditFunctions(std::map<std::string, std::function<void()>> editFunctions)
{
    this->_editFunctions = editFunctions;
}

void GUI::ToolBar::setHelpFunctions(std::map<std::string, std::function<void()>> helpFunctions)
{
    this->_helpFunctions = helpFunctions;
}
