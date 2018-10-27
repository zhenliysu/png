#include <iostream>

#include "pngHandle.h"
int main() {
    int width = 800;
    int height = 600;
    pngHandle png(width,height);


    for(int x =height/4 ;x<height/2;x++){
        for(int y=0; y<width ; y++)
        {
            png.setValue(x,y,0x00);
        }
    }
    for(int x =0 ;x<height;x++){
        for(int y=width/3; y<width/2 ; y++)
        {
            png.setValue(x,y,205);
        }
    }

    png.write("mypng.png");
    
    return 0;
}
