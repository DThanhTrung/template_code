// C++
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <queue>
#include <vector>

// C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>

#define maxn        1<<16 + 1
#define inf	        0x3f3f3f3f
#define precision   1e-6
#define mod         1000000007
#define ll long long int

using namespace std;

mutex mtx;
condition_variable cv;

int maxSize = 5;
vector<int> v;

void producer() {
    while (1) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, 
                [] {return (v.size() < maxSize);});
        
        int x = rand()%10;
        v.push_back(x);
        cout<<"Vector push: "<<x<<'\n'<<"Vector: ";
        for (auto val: v) {
            cout<<val<<' ';
        }
        cout<<'\n';
        this_thread::sleep_for(chrono::seconds(2));
        cv.notify_one();
        lock.unlock();
    }
}


void consumer() {
    while (1) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, 
                [] {return (v.size() > 0);});
        
        int x = v.back();
        v.pop_back();
        cout<<"Get from vector: "<<x<<'\n'<<"Vector: ";
        for (auto val: v) {
            cout<<val<<' ';
        }
        cout<<'\n';
        this_thread::sleep_for(chrono::seconds(2));
        cv.notify_one();
        lock.unlock();
    }
}




void Input() {
    cout<<"Loading producer and consumer\n";

    thread Producer(producer);
    thread Consumer(consumer);

    Producer.join();
    Consumer.join();
}

void Init() {

}

void Solve() {

}

void Free() {

}

int main() {
    srand(time(NULL));
    //setvbuf(stdout, NULL, _IONBF, 0);
    int NumTest=1;
    //scanf("%d", &NumTest);
    while (NumTest--) {
        Input();
        Init();
        Solve();
        Free();
    }

    return 0;
}
