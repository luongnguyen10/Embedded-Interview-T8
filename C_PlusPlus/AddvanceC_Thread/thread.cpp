#include <iostream>
#include <thread>
#include <chrono>

using namespace std

void task1(){
    int i =0;
    while(1){
        this_thread::sleep_for(chrono::seconds(1)); // làm chương trình delay 1s
        cout<<"i = "<< i++ <<endl;
    }
}

int main(){
    thread t1(task1);
    thread t2(task2);

}
