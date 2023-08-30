#include <iostream>
#include <stdint.h>
#include <string.h>

using namespace std;

class sinhvien 
{
    private:
    // /* data */
    
    public: // Khai báo các biến riêng của đối tượng đó thôi
        uint8_t ID;
        string NAME;
        uint8_t OLD;

        // sinhvien(uint8_t id, string name, uint8_t old); // Mặc định đã có

        void setNAME(string name){
            NAME = name;
        }
        // void setOLD(uint8_t old);
        
        // string getNAME();
  
};


int main(){

    sinhvien sv; // Tạo một cái đối tượng của class sinhvien; còn sv là một đối tượng

    sv.setNAME("tuan"); // Gán biến cho các đối tượng

    int key = 0;
    cout << "Nhap key: ";

    cin >> key;
    cout << key;
    return 0;
}


