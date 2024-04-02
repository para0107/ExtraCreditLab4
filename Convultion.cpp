//
// Created by tudor on 4/1/2024.
//

#include "Convultion.h"

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
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            this->kernel[i][j] = kernel[i][j];

}
void Convultion::process(const Image &src, Image &dst)
{
    for(int i = 0; i <= src.height(); i++)
        for(int j = 0; j <= src.width(); j++)
        {
            int sum = 0;
            for(int x = 0; x<=2; x++)
                for(int y = 0; y<=2; y++)
                    sum = sum + kernel[x][y] * src.get_pixel(i-x+1, j-y+1);
            dst.set_pixel(i,j,sum);

        }

}
