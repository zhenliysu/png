//
// Created by L on 18-10-26.
//

#ifndef PNG_PNGHANDLE_H
#define PNG_PNGHANDLE_H

#include "png.h"

class pngHandle{

public:
    ~pngHandle();
    pngHandle();
    pngHandle(const int width,const int height);

    void setSize(const int width,const int height);
    bool setBackground(unsigned char value);
    bool setValue(int x,int y,unsigned char value);
    bool write(char * filename);


private:


    bool isSetSize;
    char bit_depth_;//图像深度
    char color_type_;
    int width_; //图寬
    int height_;//图高

    void setBitDepth(char bit_depth);
    void setColortype(char color_type);

    unsigned char *buffer;// 0 <= gray < 255


};



#endif //PNG_PNGHANDLE_H
