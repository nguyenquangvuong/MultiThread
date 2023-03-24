
/********************************************************************************
Copyright (C) 2023, Luu Kien., Ltd. All rights reserved.
Project: Thread.cpp
Module: 
Version: 1.0
Author: 
Created: 
Modified:
<Name>
<Date>
<Change>
Released: 12-8-2022
Description:
Note: <Note>
********************************************************************************/
#include <iostream>
#include <thread>
using namespace std;

void foo(int Z) 
{ 
    for (int i = 0; i < Z; i++) { 
        cout << "Thread using function"
               " pointer as callable: " << i << endl; 
    } 
} 
  
class thread_obj { 
public: 
    void operator()(int x) 
    { 
        for (int i = 0; i < x; i++) 
            cout << "Thread using function"
                  " object as  callable: " << i << endl; 
    } 
};

int main() 
{ 
    cout << "Threads 1 and 2 and 3 " "operating independently" << endl; 
  
    // thread sử dụng function pointer - Thread 1
    thread th1(foo, 4); 
    // thread sử dụng function object - Thread 2
    thread th2(thread_obj(), 4); 

    //Define a Lambda Expression - Thread 3
    //lambda include three part: [], (), {}  (Capture list, Parameter, Funtion body)
    auto f = [](int x) 
    {       
        for (int i = 0; i < x; i++) 
            cout << "Thread using lambda"
             " expression as callable:============thread 2 " << i << endl; 
    }; 
    // thread sử dụng lamda expression 
    thread th3(f, 4); 
    //Lamda - Thread 4 - O day ->int la kieu tra ve int
    auto lamda = [](int hienthi)->int{  
        hienthi += 10; 
        // return (hienthi);
    };

    thread th4(lamda, 4);

    // chờ th1 kết thúc
    th1.join(); 
    //  chờ th2 kết thúc
    th2.join(); 
    //  chờ th3 kết thúc
    th3.join();
    // cho th4 ket thuc
    th4.join(); 
  
    return 0; 
} 

/**
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <pthread.h>

using namespace cv;
using namespace std;

#define Ten_Window "VuongNQb"

//GLOBALS
VideoCapture vcap;
Mat frame;
pthread_mutex_t frameLocker;

const string videoStreamAddress = "rtsp://admin:Taybacaa666@batbienthuydung.ddns.net:554/profile1/live";

void *UpdateFrame(void *arg)
{
    for(;;)
    {
        Mat tempFrame;
        vcap >> tempFrame;
        pthread_mutex_lock(&frameLocker);
        frame = tempFrame;
        pthread_mutex_unlock(&frameLocker);
    }
}


int main(int, char**) { 
    vcap.open(videoStreamAddress);

    pthread_mutex_init(&frameLocker,NULL);  
    pthread_t UpdThread;    
    pthread_create(&UpdThread,     //so thread
                    NULL,          //Cac thuoc tinh cai dat
                    UpdateFrame,   //Con tro chinh thuc hien
                    NULL);         //Tham so truyen vao threa neu khong co de NULL

    for(;;)
    {
        namedWindow(Ten_Window , cv::WINDOW_NORMAL);//VuongNQb
        Mat currentFrame;

        pthread_mutex_lock(&frameLocker);
        currentFrame = frame;
        pthread_mutex_unlock(&frameLocker);

        if(currentFrame.empty()){
            printf("recieved empty frame\n");
            continue;
        }
        imshow(Ten_Window , currentFrame);
        waitKey(1);
    }
}
//Mat(height, width, CV_8UC3, Scalar(0, 0, 0));  Mat(500, 1000, CV_8UC3, Scalar(0, 0, 0))
*/