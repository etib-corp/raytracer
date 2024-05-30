/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** RaytracerAth
*/

#ifndef RAYTRACERATH_HPP_
#define RAYTRACERATH_HPP_

#include "GUI/Ath.hpp"

#include "GUI/Panel.hpp"
#include "GUI/ChildPanel.hpp"
#include "GUI/ScrollableChild.hpp"

#include "GUI/Button.hpp"
#include "GUI/RadioButtonList.hpp"

#include "GUI/EditColor.hpp"
#include "GUI/EditPosition.hpp"
#include "GUI/DoubleInput.hpp"

#include "Primitive/Cylindre.hpp"
#include "Primitive/Sphere.hpp"
#include "Primitive/Plan.hpp"

#include "Texture/Checker.hpp"
#include "Texture/SolidColor.hpp"

#include "Material/Lambertian.hpp"
#include "Material/Dielectric.hpp"
#include "Material/Metal.hpp"

#include "RaytracerAth/RaytracerAddPanel.hpp"
#include "RaytracerAth/RaytracerConfigPanel.hpp"

class RaytracerATH : public GUI::ATH {
    public:
        RaytracerATH();
        ~RaytracerATH() {}

        void hide() { this->setDisplay(false); }
        void show() { this->setDisplay(true); }
        void hideSwitchShow() { this->setDisplay(!this->_display); }

        void init(sf::RenderWindow &window, sf::Clock &clock, ObjectsList &world);
        void update();
        void createMainPanel();

        void display();

        void setIndex(int index) { this->_index = index; }

        bool hasToRender() const { return this->_render; }

    protected:
        int _index = 0;
        bool _render = false;
        RaytracerConfigPanel *_confPanel;
        RaytracerAddPanel *_addPanel;

};

#endif /* !RAYTRACERATH_HPP_ */
