struct Image readBMPImage(char* imgPath);
void writeImage(struct Image , char* imgPath);
void freeImage(struct Image);
struct Image grayScale(struct Image img);
struct Image logarithmImage(struct Image img);
struct Image thresholdImgae(struct Image img, int thVal);
struct Image HistEquiImgae(struct Image img);
struct Image MeanFilter(struct Image img, int neighbour);
struct Image MedianFilter(struct Image img, int neighbour);
struct Image FourierTransform(struct Image img);
void intensity(struct Image img);
void textart(struct Image img);





