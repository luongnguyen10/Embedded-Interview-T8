#include <iostream>
#include <stdint.h>
#include <string.h>

using namespace std;

class sinhvien 
{
    private:
        // Các biến khai báo là proberty
        uint8_t ID;
        string NAME;
        int OLD;
        string LOP;

    public: 
        sinhvien(string name, int old, string lop) // Mặc định đã có
        {
            
            NAME = name;
            OLD = old;
            LOP = lop;
        }
        
        
        // Các hàm ở đây được gọi là method
        void setNAME(string name){
            NAME = name;
        }
        // void setOLD(uint8_t old);
        
        string getNAME(){
            return NAME;
        }
        // Tại sao các đối tượng này mình có thể trỏ vào nhưng vẫn phải viết hàm để trả về



};


int main(){

    sinhvien sv{"tuan", 12, "LOP12"}; // Tạo một cái đối tượng của class sinhvien; còn sv là một đối tượng

    cout << sv.getNAME() << endl;
    // cout << sv.LOP << endl; // Hàm này báo lỗi 
    // cout << sv.OLD << endl;

    return 0;
}


