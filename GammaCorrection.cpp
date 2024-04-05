//
// Created by tudor on 4/1/2024.
//

#include "GammaCorrection.h"
#include <cmath>
#include <iostream>
GammaCorrection::GammaCorrection(unsigned int Gamma)
{
    this->Gamma = Gamma;
}
void GammaCorrection::process(const Image &src, Image &dst)
{
    if(this->Gamma == 1)
        dst = src;
    else if(Gamma > 1)
    {
    for(int i = 0; i < src.height(); i++)
        for(int j = 0; j < src.width(); j++)
            //dst.set_pixel(i,j, double(pow(static_cast<double>(src.get_pixel(i,j)),static_cast<double>(Gamma))));
            dst.at(i,j) = int(pow(dst.at(i,j),this->Gamma)) % 255;
    }
//    else if(Gamma < 1)
//    {
//        for(int i = 0; i < src.height(); i++)
//            for(int j = 0; j < src.width(); j++)
//                dst.set_pixel(i,j, double(pow(static_cast<double>(src.get_pixel(i,j)),static_cast<double>(Gamma))));
//    }
}