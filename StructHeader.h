struct Image_header {
    char format[2];  // 2B for format name, "BM" in this case
    unsigned int size;  // total size of bmp file
    unsigned int garbage;  // Not needed info of 4B
    unsigned int offset;   // 4B offset, starting address of image data
};

struct Image_info_header{   
    unsigned int size;
    unsigned int width;
    unsigned int height;
    unsigned int garbage;
    unsigned int compression;
};

struct Pixel{
    unsigned char blue;
    unsigned char red;
    unsigned char green;
};


struct Image{
    struct Image_header header;
    struct Image_info_header info_header;
    void* allHeader;
    struct Pixel** pixels; 
};

