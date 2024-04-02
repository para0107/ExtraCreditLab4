//
// Created by tudor on 4/1/2024.
//

#ifndef EXTRACREDIT_GAMMACORRECTION_H
#define EXTRACREDIT_GAMMACORRECTION_H

#include "Image.h"
#include "ImageProcessing.h"
class GammaCorrection :public ImageProcessing{
public:
    unsigned int Gamma;
    void process(const Image& src, Image& dst) const ;
    GammaCorrection(unsigned int Gamma);


};


#endif //EXTRACREDIT_GAMMACORRECTION_H
