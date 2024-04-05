//
// Created by tudor on 4/1/2024.
//

#ifndef EXTRACREDIT_POINT_H
#define EXTRACREDIT_POINT_H


class Point {
private:
    int x,y;
public:
    Point();
    Point(int x, int y);
    void set_x(int x_param);
    void set_y(int y_param);
    int get_x() const;
    int get_y() const;

};


#endif //EXTRACREDIT_POINT_H
