#include <opencv2/opencv.hpp>
#include "Modifymask.h"

using namespace cv;
using namespace std;

int zBrilho;
double zContraste;

int slider1 = 50;
int slider2 = 50;

void trackbar(string windowname, int &slider1, int &slider2) {
    createTrackbar("Brilho", windowname, &slider1, 100);
    createTrackbar("Contraste", windowname, &slider2, 100);
}