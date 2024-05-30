/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** TexturePanel
*/

#include "RaytracerAth/TexturePanel.hpp"


TexturePanel::TexturePanel()
{
    this->_color1 = new GUI::EditColor();
    this->_color1->setDisplay(true);
    this->_color2 = new GUI::EditColor();
    this->_texture = nullptr;
    this->_scale = new GUI::DoubleInput("Scale");
    this->_title = "Edit Texture";
}

TexturePanel::TexturePanel(std::shared_ptr<ITexture> texture)
{
    this->_texture = texture;
    this->_color1 = new GUI::EditColor("First color");
    this->_color1->setDisplay(true);
    this->_color2 = new GUI::EditColor("Second color");
    this->_scale = new GUI::DoubleInput("Scale");
    this->_title = "Edit Texture";

    if (this->_texture == nullptr) {
        return;
    }

    switch (this->_texture->getType()) {
        case ATexture::Type::CHECKER:
            this->_color2->setDisplay(true);
            this->_scale->setDisplay(true);
            break;
        default:
            break;
    }
}

void TexturePanel::init(sf::RenderWindow &window, sf::Clock &clock, ObjectsList &world)
{
    this->_window = &window;
    this->_clock = &clock;
    this->_world = &world;
    this->_color1->init(window, clock, world);
    this->_color2->init(window, clock, world);
    this->_scale->init(window, clock, world);
}

void TexturePanel::display()
{
    if (this->_texture == nullptr || !this->hasToDisplay()) {
        return;
    }

    Color color;
    std::shared_ptr<ITexture> texture;
    ImGui::BeginListBox(this->_title.c_str());
    switch (this->_texture->getType()) {
        case ITexture::Type::CHECKER:
            texture = (dynamic_cast<Checker *>(this->_texture.get()))->getEven();
            this->_scale->setValue((dynamic_cast<Checker *>(this->_texture.get()))->getScale());
            color = dynamic_cast<SolidColor *>(texture.get())->getAlbedo();
            this->_color1->setX(color.red);
            this->_color1->setY(color.green);
            this->_color1->setZ(color.blue);
            texture = (dynamic_cast<Checker *>(this->_texture.get()))->getOdd();
            color = dynamic_cast<SolidColor *>(texture.get())->getAlbedo();
            this->_color2->setX(color.red);
            this->_color2->setY(color.green);
            this->_color2->setZ(color.blue);
            this->_color1->display();
            this->_color2->display();
            this->_scale->display();
            (dynamic_cast<Checker *>(this->_texture.get()))->setScale(this->_scale->getValue());
            color = Color(this->_color1->getX(), this->_color1->getY(), this->_color1->getZ());
            (dynamic_cast<Checker *>(this->_texture.get()))->setEven(std::make_shared<SolidColor>(color));
            color = Color(this->_color2->getX(), this->_color2->getY(), this->_color2->getZ());
            (dynamic_cast<Checker *>(this->_texture.get()))->setOdd(std::make_shared<SolidColor>(color));
            break;
        case ITexture::Type::SOLIDCOLOR:
            color = (dynamic_cast<SolidColor *>(this->_texture.get()))->getAlbedo();
            this->_color1->setX(color.red);
            this->_color1->setY(color.green);
            this->_color1->setZ(color.blue);
            this->_color1->display();
            color = Color(this->_color1->getX(), this->_color1->getY(), this->_color1->getZ());
            (dynamic_cast<SolidColor *>(this->_texture.get()))->setAlbedo(color);
            break;
        default:
            break;
    }
    ImGui::EndListBox();

}

void TexturePanel::setTexture(std::shared_ptr<ITexture> texture)
{
    this->_texture = texture;
}
