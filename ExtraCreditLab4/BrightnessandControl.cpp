//
// Created by tudor on 4/1/2024.
//

#include "BrightnessandControl.h"
#include "Image.h"
BrightnessandControl::BrightnessandControl()
{
    this->alfa = 1;
    this->beta = 0;
}
BrightnessandControl::BrightnessandControl(unsigned int alfa, int beta)
{
    this->alfa = alfa;
    this->beta = beta;
}
void BrightnessandControl::process(const Image &src, Image &dst) const
{
   Image intermediate(src.width(),src.height());
    for(  int i = 0;i < src.height(); i++)
        for(  int j = 0;j< src.width(); j++)
        {
            if(src.get_pixel( i, j) * alfa + beta > 255)
            {
                 int aux = src.get_pixel( i, j) * alfa + beta;
                while(aux > 255)
                    aux -= 255;
                dst.set_pixel(i, j, aux);
            }
            else if(src.get_pixel( i, j) * alfa + beta < 0)
            {
                int aux = src.get_pixel( i, j) * alfa + beta;
                while(aux < 0)
                    aux += 255;
                dst.set_pixel(i, j, aux);
            }

            else {
                dst.set_pixel(i, j, src.get_pixel(i, j));
            }

        }



}