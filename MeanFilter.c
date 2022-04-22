#include "StructHeader.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


struct Image MeanFilter(struct Image img, int neighbour){
    struct Image filteredImg;

    //Seting up header
    filteredImg.allHeader = img.allHeader;
    filteredImg.header.offset = img.header.offset;
    filteredImg.info_header.height = img.info_header.height;
    filteredImg.info_header.width = img.info_header.width;

    int h = img.info_header.height;
    int w = img.info_header.width;

    filteredImg.pixels = (struct Pixel**)malloc(h*sizeof(struct Pixel*));
    for(int i = 0; i < h ; i++)
        filteredImg.pixels[i] = (struct Pixel*)malloc(w*sizeof(struct Pixel));



    //Transforming pixels
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){

           
           // Calulating limit of neighbour
           int x_i = (j - neighbour/2) > 0 ? (j - neighbour/2) : 0;
           int x_f = (j + neighbour/2) < w ? (j + neighbour/2) : w - 1;

           int y_i = (i - neighbour/2) > 0 ? (i - neighbour/2) : 0;
           int y_f = (i + neighbour/2) < h ? (i + neighbour/2) : h - 1;


           // Calulating mean of Neighbour
           int count = 0, sum = 0; 
            for(int p = y_i; p <= y_f; p++){
               for(int q = x_i ; q <= x_f; q++){
                   count++;
                   sum += img.pixels[p][q].red;
               }
           }


           unsigned char mean = (unsigned char) round((sum*1.0)/count); 
           filteredImg.pixels[i][j].red = filteredImg.pixels[i][j].blue = filteredImg.pixels[i][j].green = mean;
        }
    }

    return filteredImg;
}