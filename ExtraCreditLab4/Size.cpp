//
// Created by tudor on 4/1/2024.
//

#include "Size.h"
Size::Size()
{
    this->height = 0;
    this->width = 0;
}
Size::Size(unsigned int width, unsigned int height)
{   this->width = width;
    this->height = height;
}
void Size::set_width(unsigned int widt)
{
    this->width = widt;
}
void Size::set_height(unsigned int heigh)
{
    this->height = heigh;
}
unsigned int Size::get_width() const
{
    return this->width;
}
unsigned int Size::get_height() const
{
    return this->height;
}
unsigned int Size::Area_of() const
{
    return this->height * this->width;
}
bool Size::operator==(Size &other) const
{
    return this->Area_of() == other.Area_of();
}

bool Size::operator>= (Size &other) const
{
    return this->Area_of() >= other.Area_of();
}
bool Size::operator<= (Size &other) const
{
    return this->Area_of() <= other.Area_of();
}
bool Size::operator< (Size &other) const
{
    return this->Area_of() < other.Area_of();
}
bool Size::operator> (Size &other) const
{
    return this->Area_of() > other.Area_of();
}

