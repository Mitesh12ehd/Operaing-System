#include<iostream>
#include<thread>
#include<unistd.h>
#include<mutex>
using namespace std;

mutex mtx;
int count = 0;

void task(){
    //lock the thread first
    mtx.lock();

    for(int i=0; i<10000000; i++){
        count = count + 1;
    }

    //unlock thread
    mtx.unlock();
}

int main(){
    thread t1(task);
    thread t2(task);

    t1.join();
    t2.join();
    cout << count;
    return 0;
}