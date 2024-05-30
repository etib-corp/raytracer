/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Ath
*/

#include "GUI/Ath.hpp"

void GUI::ATH::display()
{
    if (this->hasToDisplay()) {
        this->_mainPanel->display();
        // this->_controlPanel->display();
        // this->_toolBar->display();
        this->_tempPanel->display();
    }
}
