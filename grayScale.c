#include "StructHeader.h"
#include <stdlib.h>
#include <stdio.h>


struct Image grayScale(struct Image img){
    struct Image gray;
    gray.allHeader = img.allHeader;
    gray.header.offset = img.header.offset;
    gray.info_header.height = img.info_header.height;
    gray.info_header.width = img.info_header.width;

    int h = img.info_header.height;
    int w = img.info_header.width;

    gray.pixels = (struct Pixel**)malloc(h*sizeof(struct Pixel*));
    for(int i = 0; i < h ; i++)
        gray.pixels[i] = (struct Pixel*)malloc(w*sizeof(struct Pixel));


    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            unsigned char val = 0.3 * img.pixels[i][j].red + 0.59 * img.pixels[i][j].green + 0.11*img.pixels[i][j].blue;
            gray.pixels[i][j].red = gray.pixels[i][j].blue = gray.pixels[i][j].green = val;
        }
    }

    return gray;
}