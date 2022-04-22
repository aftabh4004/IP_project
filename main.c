#include<stdio.h>
#include "funHeader.h"
#include "StructHeader.h"



int main(int argc, char **argv){

    if(argc != 2){
        printf("Please provide image!");
        return 1;
    }

    
    struct Image img = readBMPImage(argv[1]);

    printf("format: %c%c\n", img.header.format[0], img.header.format[1]);
    printf("Size: %d\n", img.header.size);
    printf("offset: %d\n", img.header.offset);

    printf("==============================\n");
    printf("size of header: %d\n", img.info_header.size);
    printf("height: %d\n", img.info_header.height);
    printf("width: %d\n", img.info_header.width);
    printf("compression: %d\n", img.info_header.compression);

    intensity(img);
    struct Image gray = grayScale(img);
    // struct Image logImg = logarithmImage(gray); 
    // struct Image thImg = thresholdImgae(gray, 220);
    // struct Image equilizeImg = HistEquiImgae(gray);
    // struct Image meanFilteredImg = MeanFilter(gray, 3);
    // struct Image medianFilteredImg = MedianFilter(gray, 3);
    // struct Image transformedImg = FourierTransform(gray);
    textart(gray);



    writeImage(gray, "./OutImages/grayScale.bmp");
    // writeImage(logImg, "./OutImages/logarithm.bmp");
    // writeImage(thImg, "./OutImages/threshold.bmp");
    // writeImage(equilizeImg, "./OutImages/HistEqulize.bmp");
    // writeImage(meanFilteredImg, "./OutImages/MeanFilter.bmp");
    // writeImage(medianFilteredImg, "./OutImages/MedianFilter.bmp");
    // writeImage(transformedImg, "./OutImages/FourierTransform.bmp");





    freeImage(img);
    // freeImage(logImg);
    freeImage(gray);
    // freeImage(thImg);
    // freeImage(equilizeImg);
    // freeImage(meanFilteredImg);
    // freeImage(medianFilteredImg);
    // freeImage(transformedImg);

}