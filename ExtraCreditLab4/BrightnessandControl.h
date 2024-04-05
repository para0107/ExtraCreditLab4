//
// Created by tudor on 4/1/2024.
//

#ifndef EXTRACREDIT_BRIGHTNESSANDCONTROL_H
#define EXTRACREDIT_BRIGHTNESSANDCONTROL_H
#include "Image.h"
#include "ImageProcessing.h"

class BrightnessandControl : public ImageProcessing{
public:
    void process(const Image& src, Image& dst) const ;
unsigned int alfa;
int beta;
BrightnessandControl();
BrightnessandControl(unsigned int alfa, int beta);

};


#endif //EXTRACREDIT_BRIGHTNESSANDCONTROL_H
