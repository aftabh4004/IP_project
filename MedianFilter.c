#include "StructHeader.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void insertionSort(unsigned char arr[], int n)
{
    int i, j;
    unsigned char key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

struct Image MedianFilter(struct Image img, int neighbour){
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

           int size_x = x_f - x_i + 1;
           int size_y = y_f - y_i + 1;

           // Calulating meadian of Neighbour
           unsigned char arr[size_y * size_x];
           int count = 0, sum = 0, k = 0; 
            for(int p = y_i; p <= y_f; p++){
               for(int q = x_i ; q <= x_f; q++){
                    arr[k++] = img.pixels[p][q].red;
               }
           }

           insertionSort(arr, size_y * size_x);

           unsigned char median = arr[(size_x * size_y) /2]; 
           filteredImg.pixels[i][j].red = filteredImg.pixels[i][j].blue = filteredImg.pixels[i][j].green = median;
        }
    }

    return filteredImg;
}