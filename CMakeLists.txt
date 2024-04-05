cmake_minimum_required(VERSION 3.27)
project(ExtraCredit)

set(CMAKE_CXX_STANDARD 17)

add_executable(ExtraCredit main.cpp
        Size.cpp
        Point.cpp
        Rectangle.cpp
        Image.cpp
        ImageProcessing.cpp
        BrightnessandControl.cpp
        GammaCorrection.cpp
        Convultion.cpp
        DrawingModule.cpp)
