#include "StructHeader.h"
#include "funHeader.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.141592

struct Image FourierTransform(struct Image img){
    struct Image transformedImg;

    //Seting up header
    transformedImg.allHeader = img.allHeader;
    transformedImg.header.offset = img.header.offset;
    transformedImg.info_header.height = img.info_header.height;
    transformedImg.info_header.width = img.info_header.width;

    int h = img.info_header.height;
    int w = img.info_header.width;

    transformedImg.pixels = (struct Pixel**)malloc(h*sizeof(struct Pixel*));
    for(int i = 0; i < h ; i++)
        transformedImg.pixels[i] = (struct Pixel*)malloc(w*sizeof(struct Pixel));

    //Temp pixel storage
    long int p[h][w];

    //Transforming pixels

    // Fourier Transform

    // F(u, v) =  sigma(i = 0 to h-1)sigma(j = 0 to w - 1) f(i, j) * (cos(2.0 * PI * ((u * i)/h + (v * j)/w)) - jsin(2.0 * PI * ((u * i)/h + (v * j)/w)))
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            double real = 0, imgi = 0;
            
            // unsigned char val = 0.3 * img.pixels[i][j].red + 0.59 * img.pixels[i][j].green + 0.11*img.pixels[i][j].blue;
            // transformedImg.pixels[i][j].red = transformedImg.pixels[i][j].blue = transformedImg.pixels[i][j].green = val;
            for(int u = 0; u < 50; u++){
                for(int v = 0; v < 50; v++){
                    
                    double x = 2.0 * PI * i * u / h;
                    double y = 2.0 * PI * j * v / w;

                    real += img.pixels[u][v].red * cos(x + y);
                    imgi += img.pixels[u][v].red * sin(x + y);

                }
            }


            p[i][j] = (long int)round(sqrt(real * real  + imgi * imgi));
            



        }
    }

    //Log
    long int max = abs(p[0][0]);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(abs(p[i][j]) > max)
                max = abs(p[i][j]);
        }
    }
    // const 
    long int scale = 255.0 / log(1 + max);

    //Transforming pixels
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
           unsigned char val = (unsigned char) round(scale * log(abs(p[i][j]) + 1));
           transformedImg.pixels[i][j].red = transformedImg.pixels[i][j].blue = transformedImg.pixels[i][j].green = val;

            
        }
    }

    //FFT shift
    // IMAGE
    // Q1 Q2
    // Q3 Q4
    //swaping quad 1 to 4
    for(int i = 0; i < h/2 ; i++){
        for(int j = 0; j < w/2; j++){
            unsigned char temp = transformedImg.pixels[i][j].red;
            transformedImg.pixels[i][j].red = transformedImg.pixels[i + h/2][j + w/2].red;
            transformedImg.pixels[i + h/2][j + w/2].red = temp;
            transformedImg.pixels[i][j].blue = transformedImg.pixels[i][j].green = transformedImg.pixels[i][j].red;
            transformedImg.pixels[i + h/2][j + w/2].blue = transformedImg.pixels[i + h/2][j + w/2].green = transformedImg.pixels[i + h/2][j + w/2].red;
        }
    }
    

    
    //swaping quad 2 to 3
    for(int i = 0; i < h/2 ; i++){
        for(int j = w/2; j < w; j++){
            unsigned char temp = transformedImg.pixels[i][j].red;
            transformedImg.pixels[i][j].red = transformedImg.pixels[i + h/2][j - w/2].red;
            transformedImg.pixels[i + h/2][j - w/2].red = temp;
            transformedImg.pixels[i][j].blue = transformedImg.pixels[i][j].green = transformedImg.pixels[i][j].red;
            transformedImg.pixels[i + h/2][j - w/2].blue = transformedImg.pixels[i + h/2][j - w/2].green = transformedImg.pixels[i + h/2][j - w/2].red;
        }
    }
    return transformedImg;
}