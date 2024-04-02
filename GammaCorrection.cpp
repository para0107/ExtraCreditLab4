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
void GammaCorrection::process(const Image &src, Image &dst) const
{
    if(this->Gamma == 1)
        dst = src;
    else if(Gamma > 1)
    {
    for(int i = 0; i < src.height(); i++)
        for(int j = 0; j < src.width(); j++)
            dst.set_pixel(i,j, double(pow(static_cast<double>(src.get_pixel(i,j)),static_cast<double>(Gamma))));
    }
    else if(Gamma < 1)
    {
        for(int i = 0; i < src.height(); i++)
            for(int j = 0; j < src.width(); j++)
                dst.set_pixel(i,j, double(pow(static_cast<double>(src.get_pixel(i,j)),static_cast<double>(Gamma))));
    }
}