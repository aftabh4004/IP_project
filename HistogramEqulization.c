#include "StructHeader.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


struct Image HistEquiImgae(struct Image img){
    struct Image equilizeImg;
    equilizeImg.allHeader = img.allHeader;
    equilizeImg.header.offset = img.header.offset;
    equilizeImg.info_header.height = img.info_header.height;
    equilizeImg.info_header.width = img.info_header.width;

    int h = img.info_header.height;
    int w = img.info_header.width;

    equilizeImg.pixels = (struct Pixel**)malloc(h*sizeof(struct Pixel*));
    for(int i = 0; i < h ; i++)
        equilizeImg.pixels[i] = (struct Pixel*)malloc(w*sizeof(struct Pixel));


    //Calculate histogram
    int hist[256] = {0};
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
           hist[img.pixels[i][j].red]++; 
        }
    }

    //Running Sum of histogram
    for(int i = 1; i < 256; i++){
        hist[i] = hist[i] + hist[i - 1];
    }

    //Output Equalize histogram
    int area = h * w;
    double out_hist[256];
    for(int i = 0; i < 256; i++){
        out_hist[i] = 255 * ((hist[i] * 1.0) / area);   
    }

    int round_hist[256];
    for(int i = 0; i < 256; i++)
        round_hist[i] = (int)round(out_hist[i]);




    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
           unsigned char val = (unsigned char)round_hist[img.pixels[i][j].red]; 
           equilizeImg.pixels[i][j].red = equilizeImg.pixels[i][j].blue = equilizeImg.pixels[i][j].green = val;
        }
    }

    return equilizeImg;
}