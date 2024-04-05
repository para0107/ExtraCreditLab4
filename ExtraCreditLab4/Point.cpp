//
// Created by tudor on 4/1/2024.
//

#include "Point.h"
Point::Point()
{
    this->x = 0;
    this->y = 0;
}
Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}
int Point::get_x() const
{
    return this->x;
}
int Point::get_y() const
{
    return this->y;
}
void Point::set_x(int x_param)
{
    this->x = x_param;
}
void Point::set_y(int y_param)
{
    this->y = y_param;
}
