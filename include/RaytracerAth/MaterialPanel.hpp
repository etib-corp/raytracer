/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** MaterialPanel
*/

#ifndef MATERIALPANEL_HPP_
#define MATERIALPANEL_HPP_

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

#include "RaytracerAth/TexturePanel.hpp"

class MaterialPanel : public GUI::ChildPanel {
    public:
        MaterialPanel();
        MaterialPanel(std::shared_ptr<IMaterial> material);
        ~MaterialPanel() {}

        void init(sf::RenderWindow &window, sf::Clock &clock, ObjectsList &world);
        void display();

        void setMaterial(std::shared_ptr<IMaterial> material);

    protected:
        std::shared_ptr<IMaterial> _material;
        GUI::DoubleInput *_index;
        GUI::EditColor *_color;
        // TexturePanel *_texture;
};

#endif /* !MATERIALPANEL_HPP_ */
