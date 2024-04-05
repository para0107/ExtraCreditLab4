//
// Created by tudor on 4/1/2024.
//

#ifndef EXTRACREDIT_SIZE_H
#define EXTRACREDIT_SIZE_H


class Size {
private:
    unsigned int width;
    unsigned int height;


public:
    Size();
    Size(unsigned int width, unsigned int height);
    void set_height(unsigned int height);
    void set_width(unsigned int width);
    [[nodiscard]] unsigned int get_width() const;
    [[nodiscard]] unsigned int get_height() const;
    [[nodiscard]] unsigned int Area_of() const;
    bool operator== (Size& other) const;
    bool operator>= (Size& other) const;
    bool operator<= (Size& other) const;
    bool operator> (Size& other) const;
    bool operator< (Size& other) const;


};


#endif //EXTRACREDIT_SIZE_H
