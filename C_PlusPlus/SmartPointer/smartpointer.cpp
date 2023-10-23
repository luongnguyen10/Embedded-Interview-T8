#include <iostream>
#include <memory>

using namespace std;

void test(){
    
    unique_ptr<int> var(new int(5)); // Lưu trên phân vùng Heap
    cout<<"var: "<<*var<<endl;
}


int main(){
    
    int *ptr = new int; // Từ khoá new để cấp phát động

    *ptr = 20;

    cout << "ptr: "<< *ptr<< endl;

    int *array = new int [10];
    
    for ( int i = 0; i < 10; i++){

        array[i] = 2*i;

    }

    for ( int i = 0; i < 10; i++){
        cout<<"i: " << i<< endl;

    }

    test();


}

// Nhược điểm tự cấp phát bộ nhớ động và muốn giải phóng thì tự delete đi



