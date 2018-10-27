#include <iostream>

#include "pngHandle.h"
int main() {
    int width = 800;
    int height = 600;
    //设置图像大小，默认背景是白色
    pngHandle png(width,height);

    //设置像素值
    for(int x =height/4 ;x<height/2;x++){
        for(int y=0; y<width ; y++)
        {
            //设置成黑色
            png.setValue(x,y,0x00);
        }
    }
    for(int x =0 ;x<height;x++){
        for(int y=width/3; y<width/2 ; y++)
        {
            //设置成灰色
            png.setValue(x,y,205);
        }
    }
    //图片写出
    png.write("mypng.png");
    
    return 0;
}
