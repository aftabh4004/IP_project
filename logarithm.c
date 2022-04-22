#include "StructHeader.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


struct Image logarithmImage(struct Image img){
    struct Image logImg;

    //Seting up header
    logImg.allHeader = img.allHeader;
    logImg.header.offset = img.header.offset;
    logImg.info_header.height = img.info_header.height;
    logImg.info_header.width = img.info_header.width;

    int h = img.info_header.height;
    int w = img.info_header.width;

    logImg.pixels = (struct Pixel**)malloc(h*sizeof(struct Pixel*));
    for(int i = 0; i < h ; i++)
        logImg.pixels[i] = (struct Pixel*)malloc(w*sizeof(struct Pixel));

    //Getting max gray level in the input image
    unsigned char max = img.pixels[0][0].red;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
           if(logImg.pixels[i][j].red > max)
                max = img.pixels[i][j].red;
        }
    }

    //Calculating scaling Constant
    double scale = 255.0/log(1 + max);

    //Transforming pixels
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
           unsigned char val = (unsigned char) round(scale * log(img.pixels[i][j].red + 1));
           logImg.pixels[i][j].red = logImg.pixels[i][j].blue =logImg.pixels[i][j].green = val;

        }
    }

    return logImg;
}