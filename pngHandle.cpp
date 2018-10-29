//
// Created by L on 18-10-26.
//

#include <iostream>
#include "pngHandle.h"

pngHandle::~pngHandle(){

    delete[] buffer;

}

pngHandle::pngHandle():
isSetSize(false)
{
    setBitDepth(8);
    setColortype(0);
}

pngHandle::pngHandle(const int width, const int height):
        isSetSize(false)
{
    setBitDepth(8);
    setColortype(0);
    setSize(width, height);
}

void pngHandle::setSize(const int width,const int height){
    width_ = width;
    height_ = height;
    buffer = new unsigned char[width_*height_];
    isSetSize = true;
    setBackground(0xff);//默认设置白色
}

bool pngHandle::setBackground(unsigned char value) {
    if(!isSetSize){
        std::cerr<<"Warning: can't set background, because size wasn't set!"<<std::endl;
        return false;
    }
    for(int i = 0;i < width_*height_;i++){
        buffer[i] = value;
    }


    return true;
}


bool pngHandle::setValue(int x, int y, unsigned char value){
    if(!isSetSize){
        std::cerr<<"Warning: can't set color, because size wasn't set!"<<std::endl;
        return false;
    }
    if((x >= height_) || (y >= width_)) {
        std::cerr<<"Warning: beyond the boundary!"<<std::endl;
        return false;
    }
    buffer[x*width_+y] = value;

    return true;
}

void pngHandle::setBitDepth(char bit_depth) {
    bit_depth_ = bit_depth;
}

void pngHandle::setColortype(char color_type){
    color_type_ = color_type;
}

bool pngHandle::write(const char *filename) {
    FILE * fp = fopen(filename,"wb");
    if (!fp) {
        std::cerr << "Warning: could not open png file: " << filename << std::endl;
        return false;
    }

    //创建png_struct
    png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING,
                                                  (png_voidp)NULL,NULL,NULL);

    if (!png_ptr) {
        fclose(fp);
        std::cerr << "Warning: could not create png_ptr" << std::endl;
        return false;
    }

    //分配内存并初始化图像信息
    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        png_destroy_write_struct(&png_ptr,(png_infopp)NULL);
        std::cerr << "Warning: could not create info_ptr" << std::endl;
        return false;
    }

    //设置输出控制
    png_init_io(png_ptr, fp);
    png_set_IHDR(png_ptr, info_ptr,
                 width_, height_,             // width, height
                 bit_depth_,                  // bits per pixel -- 16 does not work with blockbuster
                 color_type_, // non-alpha options are PNG_COLOR_TYPE_RGB,PNG_COLOR_TYPE_GRAY,
                 PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_DEFAULT,
                 PNG_FILTER_TYPE_DEFAULT);

    png_write_info(png_ptr, info_ptr);
    png_byte * row_pointers[height_];
    for (int i = 0; i < height_; ++i)
    {
        row_pointers[i] = (png_byte*)(buffer+i*width_);
    }

    png_write_image(png_ptr, row_pointers);

    png_write_end(png_ptr, NULL);

    //清空内存
    if (info_ptr != NULL) png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
    if (png_ptr != NULL) png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
    if (fp != NULL) fclose(fp);
}
