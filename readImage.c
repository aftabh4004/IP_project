#include "StructHeader.h"
#include <stdio.h>
#include <stdlib.h>

struct Image readBMPImage(char* imgPath){
    FILE* fp = fopen(imgPath, "rb");
    struct Image image;
    struct Image_header header;
    struct Image_info_header info_header;

    //Reading header
    fread(header.format, sizeof(char), 2, fp);
    fread(&header.size, 4, 1, fp);
    fread(&header.garbage, 4, 1, fp);
    fread(&header.offset, 4, 1, fp);

    //Reading info header
    fread(&info_header.size, 4, 1, fp);
    fread(&info_header.width, 4, 1, fp);
    fread(&info_header.height, 4, 1, fp);
    fread(&info_header.garbage, 4, 1, fp);
    fread(&info_header.compression, 4, 1, fp);

    fseek(fp, header.offset,SEEK_SET);

    //Reading pixels
    int h = info_header.height;
    int w = info_header.width;

    image.pixels = (struct Pixel**)malloc(h*sizeof(struct Pixel*));
    for(int i = h - 1; i >= 0; i--){
        image.pixels[i] = (struct Pixel*)malloc(w*sizeof(struct Pixel));
        fread(image.pixels[i], sizeof(struct Pixel), w, fp);
    }

    //reading all header
    fseek(fp, 0, SEEK_SET);
    image.allHeader = malloc(header.offset);
    fread(image.allHeader, header.offset, 1, fp);

    image.header = header;
    image.info_header = info_header;

    fclose(fp);
    return image;
}