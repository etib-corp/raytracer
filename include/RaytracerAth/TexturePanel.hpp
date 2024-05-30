/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** TexturePanel
*/

#ifndef TEXTUREPANEL_HPP_
#define TEXTUREPANEL_HPP_

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

class TexturePanel : public GUI::ChildPanel {
    public:
        TexturePanel();
        TexturePanel(std::shared_ptr<ITexture> texture);
        ~TexturePanel() {}

        void init(sf::RenderWindow &window, sf::Clock &clock, ObjectsList &world);
        void display();
        void setTexture(std::shared_ptr<ITexture> texture);
        std::shared_ptr<ITexture> getTexture() const { return this->_texture; }

    protected:
        std::shared_ptr<ITexture> _texture;
        GUI::EditColor *_color1;
        GUI::EditColor *_color2;
        GUI::DoubleInput *_scale;
};

#endif /* !TEXTUREPANEL_HPP_ */
