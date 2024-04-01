//
// Created by tudor on 4/1/2024.
//
#include "iostream"
#include "Rectangle.h"
Rectangle::Rectangle()
{
    this->x = 0;
    this->y = 0;
    this->width = 0;
    this->height = 0;
}
Rectangle::Rectangle(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
}
int Rectangle::get_x() const
{
    return this->x;
}
int Rectangle::get_y() const
{
    return this->y;
}
int Rectangle::get_width() const
{
    return this->width;
}
int Rectangle::get_height() const
{
    return this->height;
}
void Rectangle::set_width(int width_coord)
{
    this->width = width_coord;
}
void Rectangle::set_height(int height_coord)
{
    this->height = height_coord;
}
void Rectangle::set_x(int x_coord)
{
    this->x = x_coord;
}
void Rectangle::set_y(int y_coord)
{
    this->y = y_coord;
}
void Rectangle::addition_between_points(Point &other)
{
    this->x = this->x+other.get_x();
    this->y = this->y+other.get_y();
}
void Rectangle::substraction_between_points(Point &other)
{
    this->x = this->x-other.get_x();
    this->y = this->y-other.get_y();
}
Rectangle Rectangle::operator&(const Rectangle &other) const
{
    int x_inter = std::max(this->x, other.x);
    int y_inter = std::max(this->y, other.y);
    int x2 = std::min(this->x + this->width, other.x + other.width);
    int y2 = std::min(this->x + this->height, other.x + other.height);
    int intersectWidth = std::max(0, x2 - x_inter);
    int intersectHeight = std::max(0, y2 - y_inter);
    return {x_inter, y_inter, intersectWidth, intersectHeight};
}
Rectangle Rectangle::operator|(const Rectangle &other) const
{
        int x_uni = std::min(x, other.x);
        int y_uni = std::min(y, other.y);
        int x2 = std::max(x + width, other.x + other.width);
        int y2 = std::max(y + height, other.y + other.height);
        int unionWidth = x2 - x_uni;
        int unionHeight = y2 - y_uni;
        return {x_uni, y_uni, unionWidth, unionHeight};
}


