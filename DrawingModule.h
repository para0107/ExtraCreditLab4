//
// Created by tudor on 4/2/2024.
//

#ifndef EXTRACREDIT_DRAWINGMODULE_H
#define EXTRACREDIT_DRAWINGMODULE_H

#include "Image.h"
#include "Point.h"
#include "Rectangle.h"
class DrawingModule {
private:
    Image img;
    Point p1,p2,center;
    Rectangle rectangle;
public:

     void drawCircle(Image& img, Point center, int radius);
     void drawLine(Image &img, Point p1, Point p2);
     void drawRectangle(Image &img, Rectangle r);
     void drawRectangle(Image &img, Point tl, Point br);



};


#endif //EXTRACREDIT_DRAWINGMODULE_H
