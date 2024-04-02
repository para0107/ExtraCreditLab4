//
// Created by tudor on 4/1/2024.
//

#include "Convultion.h"

void Convultion::Scale_the_pixel(Image& other)
{ for(int i = 0; i < other.height(); i++)
    for(int j = 0; j < other.width(); j++)
    if(other.get_pixel(i, j) > 255)
    {
        int aux = other.get_pixel(i, j);
        while(aux > 255)
            aux -=255;
        other.set_pixel(i, j ,aux);
    }
    else if(other.get_pixel(i, j) < 0)
    {
        int aux = other.get_pixel(i, j);
        while(aux < 0)
            aux += 255;
        other.set_pixel(i, j ,aux);
    }
}