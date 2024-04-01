//
// Created by tudor on 4/1/2024.
//

#ifndef EXTRACREDIT_IMAGEPROCESSING_H
#define EXTRACREDIT_IMAGEPROCESSING_H

#include "Image.h"
class ImageProcessing {
public:
    virtual void process(const Image& src, Image& dst) = 0;


};


#endif //EXTRACREDIT_IMAGEPROCESSING_H
