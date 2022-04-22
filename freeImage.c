#include "StructHeader.h"
#include <stdlib.h>

void freeImage(struct Image img){
    int h = img.info_header.height;
    int w = img.info_header.width;

    for(int i = h - 1; i >= 0; i--){
        free(img.pixels[i]);
    }
    free(img.pixels);
}