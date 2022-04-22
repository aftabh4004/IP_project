#include "StructHeader.h"
#include<stdio.h>

void writeImage(struct Image img, char* imgPath){
    FILE* fp = fopen(imgPath, "wb");

    fwrite(img.allHeader, img.header.offset, 1, fp);

    int h = img.info_header.height;
    int w = img.info_header.width;

    for(int i = h - 1; i >= 0; i--){
        fwrite(img.pixels[i], sizeof(struct Pixel), w, fp);
    }

    printf("\nImage saved %s\n", imgPath);
}