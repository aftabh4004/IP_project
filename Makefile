output: main.o readImage.o writeImage.o freeImage.o grayScale.o logarithm.o threshold.o HistogramEqulization.o MeanFilter.o MedianFilter.o FourierTransform.o intensity.o textart.o
	gcc main.o readImage.o writeImage.o freeImage.o grayScale.o logarithm.o threshold.o HistogramEqulization.o MeanFilter.o MedianFilter.o FourierTransform.o intensity.o textart.o -o output

main.o: main.c
	gcc -c main.c

readImage.o: readImage.c funHeader.h StructHeader.h
	gcc -c readImage.c

writeImage.o: writeImage.c funHeader.h StructHeader.h 
	gcc -c writeImage.c

freeImage.o: freeImage.c funHeader.h StructHeader.h
	gcc -c freeImage.c

grayScale.o: grayScale.c funHeader.h StructHeader.h
	gcc -c grayScale.c

logarithm.o: logarithm.c funHeader.h StructHeader.h
	gcc -c logarithm.c

threshold.o: threshold.c funHeader.h StructHeader.h
	gcc -c threshold.c


HistogramEqulization.o: HistogramEqulization.c funHeader.h StructHeader.h
	gcc -c HistogramEqulization.c

MeanFilter.o: MeanFilter.c funHeader.h StructHeader.h
	gcc -c MeanFilter.c

MedianFilter.o: MedianFilter.c funHeader.h StructHeader.h
	gcc -c MedianFilter.c

FourierTransform.o: FourierTransform.c funHeader.h StructHeader.h
	gcc -c FourierTransform.c

intensity.o: intensity.c funHeader.h StructHeader.h
	gcc -c intensity.c
	
textart.o: textart.c funHeader.h StructHeader.h
	gcc -c textart.c

clean:
	del *.o output.exe .\OutImages\*.bmp intensity.txt


