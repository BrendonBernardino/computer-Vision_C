#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void faceDetection(Mat frame) {
    CascadeClassifier faceCascade;
    CascadeClassifier eyeCascade;
    faceCascade.load("C:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml");
    eyeCascade.load("C:\\opencv\\sources\\data\\haarcascades\\haarcascade_eye.xml");

    vector<Rect> faces;
    vector<Rect> eyes;

    faceCascade.detectMultiScale(frame, faces, 1.1, 10);
    eyeCascade.detectMultiScale(frame, eyes, 1.1, 10);

    for (int i = 0; i < faces.size(); i++) {
        rectangle(frame, faces[i].tl(), faces[i].br(), Scalar(0, 255, 0), 1);
    }
    for (int j = 0; j < eyes.size(); j++) {
        rectangle(frame, eyes[j].tl(), eyes[j].br(), Scalar(255, 0, 0), 1);
    }
}