#include "StructHeader.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


struct Image thresholdImgae(struct Image img, int thVal){
    struct Image thImg;
    thImg.allHeader = img.allHeader;
    thImg.header.offset = img.header.offset;
    thImg.info_header.height = img.info_header.height;
    thImg.info_header.width = img.info_header.width;

    int h = img.info_header.height;
    int w = img.info_header.width;

    thImg.pixels = (struct Pixel**)malloc(h*sizeof(struct Pixel*));
    for(int i = 0; i < h ; i++)
        thImg.pixels[i] = (struct Pixel*)malloc(w*sizeof(struct Pixel));


    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
           
            if(img.pixels[i][j].red > thVal){
                
                thImg.pixels[i][j].red = thImg.pixels[i][j].blue = thImg.pixels[i][j].green = 0;
            }
            else
                thImg.pixels[i][j].red = thImg.pixels[i][j].blue = thImg.pixels[i][j].green = 255;
        
        }
    }

    return thImg;
}