
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
Released: 30-3-2022
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