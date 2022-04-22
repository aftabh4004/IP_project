#include "StructHeader.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void textart(struct Image img){
    char* gtoText[] = {"  ","..", "--", "aa", "OO", "\%\%", "##", "@@"};
    FILE *fp = fopen("vaniimage.txt", "w");
    int h = img.info_header.height;
    int w = img.info_header.width;
    printf("h = %d w = %d\n", h, w);
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int index = img.pixels[i][j].red/32;
            fprintf(fp, "%s", gtoText[index]);
            printf("%s", gtoText[index]);
        }
        printf("\n");
        fprintf(fp, "\n");
    }

    printf("This is a gift");

}