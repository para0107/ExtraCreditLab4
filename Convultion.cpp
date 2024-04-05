//
// Created by tudor on 4/1/2024.
//
#include <iostream>
#include "Convultion.h"
#define kerner_w 3
#define kernel_h 3

//int Scale_the_pixel(Image& other)
//{ for(int i = 0; i < other.height(); i++)
//    for(int j = 0; j < other.width(); j++)
//    if(other.get_pixel(i, j) > 255)
//    {
//        int aux = other.get_pixel(i, j);
//        while(aux > 255)
//            aux -=255;
//        other.set_pixel(i, j ,aux);
//    }
//    else if(other.get_pixel(i, j) < 0)
//    {
//        int aux = other.get_pixel(i, j);
//        while(aux < 0)
//            aux += 255;
//        other.set_pixel(i, j ,aux);
//    }
//}
//int scale_this_pixel(int i, int j, Image& other)
//{ if(other.get_pixel(i, j) >=0 and other.get_pixel(i,j) <= 255)
//    return other.get_pixel(i, j);
//    if(other.get_pixel(i, j) > 255)
//    {
//        int aux = other.get_pixel(i, j);
//        while(aux > 255)
//            aux -=255;
//        return aux;
//    }
//    else if(other.get_pixel(i, j) < 0)
//    {
//        int aux = other.get_pixel(i, j);
//        while(aux < 0)
//            aux += 255;
//        return aux;
//    }
//    else return other.get_pixel(i, j);
//}
Convultion::Convultion(scale_this_pixel func, const int kernel[3][3])
{ this->func = func;
    for(int i = 0; i < kernel_h; i++)
        for(int j = 0; j < kerner_w; j++)
            this->kernel[i][j] = kernel[i][j];

}

int Convultion::Convolve(Image &roi) const
{
    int s = 0;
    for (unsigned int i = 0; i < roi.height(); i++)
    {
        for (unsigned int j = 0; j < roi.width(); j++)
        {
            s += kernel[i][j] * roi.at(j, i);
        }
    }
    return func(s);

}

void Convultion::process(const Image &src, Image &dst)
{
//    for(int i = 0; i <= src.height(); i++)
//        for(int j = 0; j <= src.width(); j++)
//        {
//            int sum = 0;
//            for(int x = 0; x<=2; x++)
//                for(int y = 0; y<=2; y++)
//                    sum = sum + kernel[x][y] * src.get_pixel(i-x+1, j-y+1);
//            dst.at(i,j) = static_cast<char>(sum);
//
//        }

    Image aux = src;
    Image temp;
    dst = Image(src.width() - (kerner_w - 1), src.height() - kernel_h + 1);
    for (unsigned int i = 1; i < src.height() - kernel_h / 2; i++)
    {
        for (unsigned int j = 1; j < src.width() - kerner_w / 2; j++)
        {
            aux.getROI(temp, j - kerner_w / 2, src.height() - kernel_h / 2 - i + 1, kerner_w, kernel_h);
            dst.at(j - kerner_w / 2, i - kernel_h/ 2) = Convolve(temp);
        }
    }

}
