//
// Created by tudor on 4/1/2024.
//
#include <iostream>
#include "BrightnessandControl.h"
#include "Image.h"
BrightnessandControl::BrightnessandControl()
{
    this->alfa = 1;
    this->beta = 0;
}
BrightnessandControl::BrightnessandControl(unsigned int alfa, int beta)
{ if(alfa == 0) throw ("error");
    this->alfa = alfa;
    this->beta = beta;
}
void BrightnessandControl::process(const Image &src, Image &dst)
{
//   Image intermediate(src.width(),src.height());
//    for(  int i = 0;i < src.height(); i++)
//        for(  int j = 0;j< src.width(); j++)
//        {
//            if(src.get_pixel( i, j) * alfa + beta > 255)
//            {
//                 int aux = src.get_pixel( i, j) * alfa + beta;
//                while(aux > 255)
//                    aux -= 255;
//                dst.set_pixel(i, j, aux);
//            }
//            else if(src.get_pixel( i, j) * alfa + beta < 0)
//            {
//                int aux = src.get_pixel( i, j) * alfa + beta;
//                while(aux < 0)
//                    aux += 255;
//                dst.set_pixel(i, j, aux);
//            }
//
//            else {
//                dst.set_pixel(i, j, src.get_pixel(i, j));
//            }
//
//        }

//dst=Image(src);

    for (unsigned int i = 0; i < dst.height(); i++) {
        for (unsigned int j = 0; j < dst.width(); j++) {
            float a =  alfa * static_cast<float>(dst.at(i, j)) + beta;
            if (a < 0)
                while(a < 0)
                    a += 255;
            if (a > 255)
                a = int(a) % 255;
            dst.at(i, j) = static_cast<unsigned char>(a);
        }
    }

}