//
// Created by tudor on 4/2/2024.
//
#include <stdlib.h>
#include <math.h>
#include "DrawingModule.h"
#include <iostream>
//DrawingModule::DrawingModule(Image img, Point p1, Point p2,Point center, Rectangle rct)  {
//    this->img = img;
//    this->p1 = p1;
//    this->p2 = p2;
//    this->rectangle = rct;
//    this->center = center;

void DrawingModule::drawCircle(Image& img, Point center,  int radius)
{ // // midpoint circle drawing algorithm
    int up = img.height() - (center.get_y() + radius);
    int down = img.height() - (center.get_y() - radius + 2);
    int right = center.get_x() + radius - 1;
    int left = center.get_x() - radius + 1;
    if (right >= img.width() || left < 0)throw std::error_code();
    if (up < 0 || down >= img.height())throw std::error_code();

    for (int i = up; i <= down; i++)
    {
        for (int j = left; j <= right; j++)
        {
            int x = sqrt(pow(abs(center.get_x() - j), 2) + pow(abs(int((img.height() - center.get_y() - 1) - i)), 2));
            if (x <= radius and radius <= x + 1)
            {
                //this point is in the circle
                img.at(j, i) = 7;
            }
        }
    }
}
void DrawingModule::drawLine(Image& img, Point X, Point Y)
{ // Bresenham's line drawing algorithm
    if( X.get_x() != Y.get_x() and X.get_y()!=Y.get_y())
        throw std::error_code();
    else
        if(X.get_x() == Y.get_x())
            for(int i = std::min(X.get_y(),Y.get_y())-1; i < std::max(X.get_y(),Y.get_y());i++ )
                img.at(X.get_x(), i) = 255;
        else
        if(X.get_y() == Y.get_y())
            for(int i = std::min(X.get_x(),Y.get_x())-1; i < std::max(X.get_x(),Y.get_x());i++ )
                img.at(i, X.get_y()) = 255;

}

void DrawingModule::drawRectangle(Image& img, Rectangle r) {

    unsigned int x = r.get_x(), y = r.get_y(), width = r.get_width(), height = r.get_height();
   for(int  i = r.get_x(); i <= r.get_x()+r.get_height(); i++)
       for(int j = r.get_y(); j <= r.get_y(); j++)
           img.at(i,j) = static_cast<unsigned char >(255);

}

void DrawingModule::drawRectangle(Image& img, Point tl, Point br) {

  if(tl.get_x() > br.get_x())
  {
      int aux = tl.get_x();
      tl.set_x(br.get_x());
      br.set_x(aux);
  }
    if(tl.get_y() > br.get_y())
    {
        int aux = tl.get_y();
        tl.set_y(br.get_y());
        br.set_y(aux);
    }
    for (int i = tl.get_x(); i <= br.get_x();i++) {
        for(int j = tl.get_y(); j <= br.get_y(); j++)
        img.at(i,j) = static_cast<unsigned char>(254);
    }

}