/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** RaytracerAddPanel
*/

#ifndef RAYTRACERADDPANEL_HPP_
#define RAYTRACERADDPANEL_HPP_

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
#include "Primitive/Cone.hpp"
#include "Primitive/Plan.hpp"

#include "Texture/Checker.hpp"
#include "Texture/SolidColor.hpp"

#include "Material/Lambertian.hpp"
#include "Material/Dielectric.hpp"
#include "Material/Metal.hpp"


class RaytracerAddPanel : public GUI::Panel {
    public:
        RaytracerAddPanel();
        ~RaytracerAddPanel() {}

        void init(sf::RenderWindow &window, sf::Clock &clock, ObjectsList &world);

    protected:
        GUI::RadioButtonList *_shapes;
        GUI::RadioButtonList *_materials;
        GUI::ChildPanel *_textureConf;
        GUI::EditColor *_color;
        GUI::RadioButton *_checker;
        GUI::Button *_createButton;
};

#endif /* !RAYTRACERADDPANEL_HPP_ */
