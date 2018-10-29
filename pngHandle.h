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
    //设置图片大小
    void setSize(const int width,const int height);
    //设置图片背景
    bool setBackground(unsigned char value);
    //设置像素值
    bool setValue(int x,int y,unsigned char value);
    //图片写出
    bool write(const char * filename);


private:


    bool isSetSize;//图片大小是否已经设置标志
    char bit_depth_;//图像深度
    char color_type_;//颜色类型
    int width_; //图宽
    int height_;//图高

    //设置图像深度，功能暂不开放
    void setBitDepth(char bit_depth);
    //设置颜色类型，功能暂不开放
    void setColortype(char color_type);

    unsigned char *buffer;// 0 <= gray < 255


};



#endif //PNG_PNGHANDLE_H
