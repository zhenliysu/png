#include <iostream>

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <png.h>
#include "pngHandle.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
//
//    FILE *fp = NULL;
//    png_structp png_ptr = NULL;
//    png_infop info_ptr = NULL;
//    png_bytep row = NULL;
//    int width = 800;
//    int height = 600;
//    int depth = 8;
//    char *title = "This is my test image";
//
//    fp = fopen("./test.png", "wb");
//    if(fp == NULL)
//    {
//        printf("Could not open file test.png for writing \n");
//        return -1;
//    }
//
//    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
//    if(png_ptr == NULL)
//    {
//        printf("Could not allocate write struct \n");
//        return -2;
//    }
//
//    info_ptr = png_create_info_struct(png_ptr);
//    if(info_ptr == NULL)
//    {
//        printf("Could not allocate info struct \n");
//        return -3;
//    }
//
//    if(setjmp(png_jmpbuf(png_ptr)))
//    {
//        printf("Error during png creation \n");
//        return -4;
//    }
//
//    png_init_io(png_ptr, fp);
//
//    png_set_IHDR(png_ptr, info_ptr, width, height,
//                 depth, PNG_COLOR_TYPE_GRAY, PNG_INTERLACE_NONE,
//                 PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
//
//
//    if(title != NULL)
//    {
//        png_text title_text;
//        title_text.compression = PNG_TEXT_COMPRESSION_NONE;
//        title_text.key = "Title";
//        title_text.text = title;
//        png_set_text(png_ptr, info_ptr, &title_text, 1);
//    }
//
//    png_write_info(png_ptr, info_ptr);
//
//    row = (png_bytep)malloc(width*sizeof(png_byte));
//
//    int x, y;
//
//    for (y = 0; y < height; y++) //0xff白 0x00黑
//    {
//        for (x = 0; x < width; x++)
//        {
//            if (x == 0 || x == (width - 1) || y == 0 || y == (height - 1))
//            {
//                row[x + 0] = 0xff;
//                row[x + 1] = 0xff;
//                row[x + 2] = 0xff;
//            }
//            else
//            {
//                row[x + 0] = 0x00;
//                row[x + 1] = 0x00;
//                row[x + 2] = 0x00;
//            }
//        }
//        png_write_row(png_ptr, row);
//    }
//
//    // End write
//    png_write_end(png_ptr, NULL);
//    if (fp != NULL) fclose(fp);
//    if (info_ptr != NULL) png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
//    if (png_ptr != NULL) png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
//    if (row != NULL) free(row);

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