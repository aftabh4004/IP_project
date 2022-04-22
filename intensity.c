#include "StructHeader.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void intensity(struct Image img){
    struct Image logImg;

    int h = img.info_header.height;
    int w = img.info_header.width;

    FILE* fp = fopen("intensity.txt", "w");


    //Transforming pixels
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            fprintf(fp, "[%d, %d] red  = %u blue = %u green = %u\n", i, j, img.pixels[i][j].red,img.pixels[i][j].blue, img.pixels[i][j].green);
        }
    }

    printf("Intensity written ./intensity.txt\n");
}