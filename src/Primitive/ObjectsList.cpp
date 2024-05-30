/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** ObjectsList
*/

#include "Primitive/ObjectsList.hpp"

ObjectsList::ObjectsList()
{
    this->_type = NONE;
}

ObjectsList::ObjectsList(std::shared_ptr<APrimitive> object)
{
    this->add(object);
    this->_type = NONE;
}

ObjectsList::~ObjectsList()
{
}

bool ObjectsList::hit(const Ray &ray, const Interval& ray_t, HitRecord &record) const
{
    HitRecord tempRecord;
    bool hitAnything = false;
    double closest = ray_t.getMax();

    for (const auto &object : this->_objects) {
        if (object->hit(ray, Interval(ray_t.getMin(), closest), tempRecord)) {
            hitAnything = true;
            closest = tempRecord.t;
            record = tempRecord;
        }
    }
    return hitAnything;
}

void ObjectsList::add(const std::shared_ptr<APrimitive>& object)
{
    this->_objects.emplace_back(object);
}

void ObjectsList::clear()
{
    this->_objects.clear();
}
