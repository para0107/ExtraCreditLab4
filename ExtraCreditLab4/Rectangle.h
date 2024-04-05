//
// Created by tudor on 4/1/2024.
//

#ifndef EXTRACREDIT_RECTANGLE_H
#define EXTRACREDIT_RECTANGLE_H
#include "Point.h"

class Rectangle {
private:
    int x,y;
    int width, height;
public:
    Rectangle();
    Rectangle(int x,int y,int width, int height);
    void set_x(int x_coord);
    void set_y(int y_coord);
    void set_width(int width_coord);
    void set_height(int height_coord);
    [[nodiscard]] int get_x() const;
    [[nodiscard]] int get_y() const;
    [[nodiscard]] int get_width() const;
    [[nodiscard]] int get_height() const;
    void addition_between_points(Point& other);
    void substraction_between_points(Point& other);
    Rectangle operator&(const Rectangle& other) const;
    Rectangle operator|(const Rectangle& other) const;

};


#endif //EXTRACREDIT_RECTANGLE_H
