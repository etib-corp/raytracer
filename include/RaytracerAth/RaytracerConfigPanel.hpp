/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** RaytracerConfigPanel
*/

#ifndef RAYTRACERCONFIGPANEL_HPP_
#define RAYTRACERCONFIGPANEL_HPP_

#include "RaytracerAth/TransformPanel.hpp"
#include "RaytracerAth/MaterialPanel.hpp"

class RaytracerConfigPanel : public GUI::Panel {
    public:
        RaytracerConfigPanel();
        ~RaytracerConfigPanel() {}

        void init(sf::RenderWindow &window, sf::Clock &clock, ObjectsList &world);

        void display();

        void setObject(std::shared_ptr<APrimitive> object);

    protected:
        std::string _name;
        std::shared_ptr<APrimitive> _object;
        TransformPanel *_transform;
        MaterialPanel *_material;
        TexturePanel *_texture;
};

#endif /* !RAYTRACERCONFIGPANEL_HPP_ */
