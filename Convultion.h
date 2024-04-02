//
// Created by tudor on 4/1/2024.
//

#ifndef EXTRACREDIT_CONVULTION_H
#define EXTRACREDIT_CONVULTION_H

#include "ImageProcessing.h"
#include "Image.h"
//#include <functional>
//typedef int scale_this_pixel(int i, int j, Image& other);
typedef int (*scale_this_pixel)(int input);
class Convultion :public ImageProcessing{
public:
        Convultion( scale_this_pixel func, const int kernel[3][3]);
        void process(const Image& src, Image&dst) override;
private:
    int kernel[3][3];
    scale_this_pixel func;

};


#endif //EXTRACREDIT_CONVULTION_H
