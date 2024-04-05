#pragma once

#ifndef EXTRACREDIT_CONVULTION_H
#define EXTRACREDIT_CONVULTION_H

#include "ImageProcessing.h"
#include "Image.h"

typedef int (*scale_this_pixel)(int input);

class Convultion :public ImageProcessing{

public:
        Convultion( scale_this_pixel func, const int kernel[3][3]);
        void process(const Image& src, Image&dst) ;
private:
    int kernel[3][3];
    scale_this_pixel func;
    int Convolve(Image& roi)const;

};


#endif //EXTRACREDIT_CONVULTION_H
