#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <time.h>
#include "Modifymask.h"
#include "Detection.h"

using namespace cv;
using namespace std;

void captureWebcam(Mat frame) {
    VideoCapture cap(0);
    string janela_name = "Webcam";

    int num_frames = 1;
    double fpsCam;
    clock_t start, end;

    double fps;

    cap.set(3, 320);//640
    cap.set(4, 240);//480
    cap.set(10, 100);//brilho

    if (!cap.isOpened()) {
        cout << "Camera nao esta disponivel" << endl;
        return;
    }

    double dLargura = cap.get(CAP_PROP_FRAME_WIDTH);
    double dAltura = cap.get(CAP_PROP_FRAME_HEIGHT);

    cout << "Resolucao do video: " << dLargura << " x " << dAltura << endl;


    trackbar(janela_name, slider1, slider2);

    while (true) {
        start = clock();
        
        cap >> frame;

        fps = cap.get(CAP_PROP_FPS);
        cout << "fps: " << fps << endl;
        
        bool stateCam = cap.read(frame);
        if (stateCam == false) {
            cout << "Webcam foi desconectada" << endl;
            cin.get();
            break;
        }
        faceDetection(frame);
        Mat newFrame;
        zBrilho = slider1 - 50;
        zContraste = slider2 / 50.0;
        frame.convertTo(newFrame, -1, zContraste, zBrilho);

        end = clock();

        double seconds = (double(end) - double(start)) / double(CLOCKS_PER_SEC);

        fpsCam = double(num_frames) / double(seconds);

        putText(newFrame, "FPS: " + to_string(fpsCam), {20, 30}, FONT_HERSHEY_SIMPLEX, 0.5 ,Scalar(0, 255, 0), 1.7);

        namedWindow(janela_name, WINDOW_NORMAL);
        imshow(janela_name, newFrame);

        char tecla_press = waitKey(1)/* && 0xff*/;
        if (tecla_press == 'p')
            break;
    }

    cap.release();
    destroyAllWindows();
}


int main() {
    Mat frame;

    captureWebcam(frame);

    return 0;
}