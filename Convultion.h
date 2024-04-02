//
// Created by tudor on 4/1/2024.
//

#ifndef EXTRACREDIT_CONVULTION_H
#define EXTRACREDIT_CONVULTION_H

#include "ImageProcessing.h"
#include <functional>

class Convultion :public ImageProcessing{
    public:
        Image& Kernel;
        using Scale_the_pixel = std::function<void(Image&)>;
        Scale_the_pixel scaleThePixel;
        //static void Scale_the_pixel(Image& other);
        void process(const Image& src, Image& dst) const ;
        Convultion(Image kernel, Scale_the_pixel scaleThePixel1 );

};


#endif //EXTRACREDIT_CONVULTION_H
