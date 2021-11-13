#pragma once
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

extern int zBrilho;
extern double zContraste;

extern int slider1;
extern int slider2;

void trackbar(string windowname, int &slider1, int &slider2);
