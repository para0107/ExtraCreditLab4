//
// Created by tudor on 4/1/2024.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Image.h"
Image::Image()
{
    this->m_data = nullptr;
    this->m_height = 0;
    this->m_width = 0;
}
Image::Image(unsigned int w, unsigned int h)
{
    this->m_width = w;
    this->m_height = h;
    this->m_data = new unsigned char* [h];
    for(int i = 0;i < h ; i ++)
    {
        m_data[i] = new unsigned char [w];
        for(int j = 0; j < w; j ++)
        {
            m_data[i][j] = 0;
        }
    }
}
Image::Image(const Image &other)
{
    this->m_data = other.m_data;
    this->m_width = other.m_width;
    this->m_height = other.m_height;
}

Image &Image::operator=(const Image &other)
{
        if (this != &other) {
            if (m_data != nullptr) {
                for (unsigned int i = 0; i < m_height; ++i) {
                    delete[] m_data[i];
                }
                delete[] m_data;
            }
            m_width = other.m_width;
            m_height = other.m_height;

            m_data = new unsigned char*[m_height];
            for (unsigned int i = 0; i < m_height; ++i)
            {
                m_data[i] = new unsigned char[m_width];
            }

            // Copy pixel data
            for ( int i = 0; i < m_height; i++) {
                for(int j = 0; j <m_width; j++)
                    m_data[i][j] = other.m_data[i][j];
            }
        }
        return *this;
    }
Image::~Image()
{
    if (m_data != nullptr)
    {
            for ( int i = 0; i < m_height; i++)
            {
                delete[] m_data[i];
            }
            delete[] m_data;
    }
}
void Image::set_width(unsigned int wid)
{
    this->m_width = wid;
}
void Image::set_height(unsigned int hei)
{
    this->m_height = hei;
}
unsigned int Image::height() const
{
    return this->m_height;
}
unsigned int Image::width() const
{
    return this->m_width;
}
Size Image::size() const
{
    return {this->m_width, this->m_height};
}
bool Image::isEmpty() const
{
    return (m_data == nullptr and m_height == 0 and m_width == 0);
}
std::istream& operator>>(std::istream& is, Image& dt)
{   std::string magic;
    std::getline(is, magic);
    if(magic != "P2")
    {
        std::cout<<"Invalid number"<<std::endl;
        return is;
    }

    std::string comment;
    std::getline(is,comment);

    is>>dt.m_width;
    is>>dt.m_height;
    dt.m_data = new unsigned char*[dt.m_height];
    for (int i = 0; i < dt.m_height; i++) {
        dt.m_data[i] = new unsigned char[dt.m_width];
        for (int j = 0; j < dt.m_width; ++j) {
            int pixelValue;
            is >> pixelValue;
            dt.m_data[i][j] = static_cast<unsigned char>(pixelValue);
        }
    } return is;
}
std::ostream& operator<<(std::ostream& os, const Image& dt)
{
    os<<"P2"<<std::endl;
    os<<"# Simple pgm image example"<<std::endl;
    os<<dt.m_width<<" "<<dt.m_height<<std::endl;
    os<<"255"<<std::endl;
    for(int i = 0; i < dt.m_height; i++)
    {
        for(int j = 0; j < dt.m_width; j++)
            os<<dt.m_data[i][j]<<" ";
        os<<std::endl;
    }
    return os;
}
bool Image::load(std::string imagePath)
{
    std::ifstream f(imagePath);
    if(!(f.is_open()))
    {   std::cout<<"Failed to open";
        return false;
    }
    if(!(f >> *this))
    {
        std::cout<<"Failed to read";
        return false;
    }
    f.close();
    return true;
}
bool Image::save(std::string imagePath) const
{
    std::ofstream g(imagePath);
    if(!g.is_open())
    {
        std::cout<<"This file is not open:"<<imagePath;
        return false;
    }
    g<<*this;
    g.close();
    return true;
}
Image Image::zeros(unsigned int width, unsigned int height)
{     Image image(width, height);
    for (unsigned int i = 0; i < height; ++i) {
        for (unsigned int j = 0; j < width; ++j) {
            image.m_data[i][j] = 0;
        }
    }
    return image;
}
Image Image::ones(unsigned int width, unsigned int height)
{
    Image image(width, height);
    for (unsigned int i = 0; i < height; ++i) {
        for (unsigned int j = 0; j < width; ++j) {
            image.m_data[i][j] = 1;
        }
    }
    return image;
}
unsigned char& Image::at(unsigned int x, unsigned int y)
{
    if (x > m_width)
        throw std::out_of_range("X_coordonate outside the width line");
    if (y > m_height)
        throw std::out_of_range("Y_coordonate outside the height line");
    return m_data[x][y];
}
unsigned char& Image::at(Point pt)
{
    if(pt.get_x() > m_width)
        throw std::out_of_range("X_coordonate outside the width line");
    if (pt.get_y() > m_height)
        throw std::out_of_range("Y_coordonate outside the height line");
    return m_data[pt.get_x()][pt.get_y()];
}
unsigned char* Image::row(int y)
{
    if( y > m_height)
        throw std::out_of_range("This is outside the height line");
    return m_data[y];

}
Image Image::operator+(const Image &i) const
{
    if (!(this->m_height == i.m_height and this->m_width == i.m_width))
        throw std::out_of_range("this images have different ranges");
    else
    { Image new_imagine;
        new_imagine.m_height = this->m_height;
        new_imagine.m_width = this->m_width;
        for(int x = 0; x < m_height; x++)
            for(int j = 0; j < m_width; j++)
                new_imagine.m_data[x][j] += i.m_data[x][j];
    return new_imagine;
    }
}
Image Image::operator-(const Image &i) const
{
    if (!(this->m_height == i.m_height and this->m_width == i.m_width))
        throw std::out_of_range("this images have different ranges");
    else
    {
        Image new_imagine(m_width, m_height);
        new_imagine.m_data = m_data;
        for (int x = 0; x < m_height; x++)
            for (int j = 0; j < m_width; j++)
                new_imagine.m_data[x][j] -= i.m_data[x][j];
        return new_imagine;
    }
}
Image Image::operator*(double s)
{
    Image new_image(m_width,m_height);
    new_image.m_data = m_data;

    for(int i = 0; i < m_height; i++)
        for(int j = 0; j < m_width; j++)
            new_image.m_data[i][j] = static_cast<unsigned char>(static_cast<double>(new_image.m_data[i][j]*s));

    return new_image;
}
bool Image::getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
    if(x+height > m_height or y+width > m_width)
        return false;

        roiImg.m_width = width;
        roiImg.m_height = height;
        for(unsigned int i = x; i < height; i++)
            for(unsigned int j = y; j< width; j++)
                roiImg.m_data[i][j] = this->m_data[i][j];
        return true;

}
bool Image::getROI(Image &roiImg, Rectangle roiRect)
{
    if(roiRect.get_x()+roiRect.get_height() > m_height or roiRect.get_y()+roiRect.get_width() > m_width)
        return false;
    roiImg = Image(roiRect.get_width(),roiRect.get_height());
    for(int i = roiRect.get_x(); i < roiRect.get_height(); i++)
        for(int j = roiRect.get_y(); j< roiRect.get_width(); j++)
            roiImg.m_data[i][j] = this->m_data[i][j];
    return true;
}
Image Image::add_each_pixel_with_scalar( unsigned int s)
{
    for(int i = 0; i < m_height; i++)
        for(int j = 0; j < m_width; j++)
            m_data[i][j] =static_cast<char>(static_cast<unsigned int>(m_data[i][j] + s));
    return *this;
}
int Image::get_pixel(int i, int j) const
{
    return this->m_data[i][j];
}
void Image::set_pixel(int i, int j ,int val)
{
    this->m_data[i][j] = val;
}
