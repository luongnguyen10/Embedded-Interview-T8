#include <iostream>
#include <stdint.h>
#include <string.h>

using namespace std;
class DoiTuong{
    public: // Phạm vu truy cập

        DoiTuong(string ten, int tuoi){ // Đối tượng đầu tiên được gọi là Conductor
            DoiTuong::ten = ten;   // Có tham số đầu vào
            DoiTuong::tuoi = tuoi;
        }

        ~DoiTuong(){
            cout<<"Break: "<<DoiTuong::ten<<endl;
        }
        string ten;  // Property
        int tuoi;

        void nhapThongTin(string ten, int tuoi){
            DoiTuong::ten = ten;
            DoiTuong::tuoi = tuoi;
            }

        void hienThi(){ 
            cout<<"Ten: "<<DoiTuong::ten<<endl;
            cout<<"Tuoi: "<<DoiTuong::tuoi<<endl;
        }
};

int main(int argc, char const *argv[]){
    DoiTuong dt("Tuan", 21); // Object dt thuộc Class Doituong
    
    // dt.nhapThongTin("Hoang", 21);
    dt.hienThi();
}
