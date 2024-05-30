/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** TransformPanel
*/

#ifndef TRANSFORMPANEL_HPP_
#define TRANSFORMPANEL_HPP_

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
#include "Primitive/Cone.hpp"

#include "Texture/Checker.hpp"
#include "Texture/SolidColor.hpp"

#include "Material/Lambertian.hpp"
#include "Material/Dielectric.hpp"
#include "Material/Metal.hpp"

class TransformPanel : public GUI::ChildPanel {
    public:
        TransformPanel();
        TransformPanel(std::shared_ptr<APrimitive> object);
        ~TransformPanel() {}

        void init(sf::RenderWindow &window, sf::Clock &clock, ObjectsList &world);
        void display();

        void setObject(std::shared_ptr<APrimitive> object);

    protected:
        std::shared_ptr<APrimitive> _object;
        GUI::EditPosition *_position;
        GUI::DoubleInput *_radius;
        GUI::DoubleInput *_depth;
};

#endif /* !TRANSFORMPANEL_HPP_ */
