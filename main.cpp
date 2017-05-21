/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hesham
 *
 * Created on April 23, 2017, 9:56 AM
 */

#include <cstdlib>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/core.hpp>
#include<iostream>
#include<string>
#include <opencv2/videoio/videoio_c.h>
#include <opencv2/videoio.hpp>
using namespace std;
using namespace cv;

/*
 * 
 * 
 */
string intToString(int number) {


    stringstream ss;
    ss << number;
    return ss.str();
}

int main(int argc, char** argv) {
    const string winName = "Video Capture";
    namedWindow(winName, WINDOW_AUTOSIZE);
    VideoCapture cap(0);
    VideoWriter vidWriter;
    string fileName = winName;
    fileName.append(".avi");
    //    int fcc=cap.get(CAP_PROP_FOURCC);
    double fps = cap.get(CAP_PROP_FPS);
    cout << fps << endl;
    Size frameSize(cap.get(CAP_PROP_FRAME_WIDTH), cap.get(CAP_PROP_FRAME_HEIGHT));
    int fcc = CV_FOURCC('D', 'I', 'V', '3');
    vidWriter = VideoWriter(fileName, fcc, fps, frameSize, true);
    if (!vidWriter.isOpened()) {
        cout << "Error Opening Video Writer!!" << endl;
        getchar();
        return -1;
    }
    if (!cap.isOpened()) {
        cout << " Error initializing video!" << endl;
        return -1;
    }
    Mat frame;
    bool bSuc;
    while (1) {
        bSuc = cap.read(frame);
        vidWriter.write(frame);
        if (!bSuc) {
            cout << "Error reading video stream!" << endl;
            break;
        }
        imshow(winName, frame);

        switch (waitKey(1)) {
            case 27:
                return 0;

        }
    }

    return 0;
}

