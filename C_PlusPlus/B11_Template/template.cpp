#include <iostream>

using namespace std;

// int sum1 (int a, int b){
//     return a + b;
// }

// double sum2 (double a, double b){
//     return a + b;
// }

// int main(){

//     cout << sum1(4,5) << endl;
//     cout << sum2(3.5 , 2.2) << endl;
    
//     return 0;
// }

template <typename datatype>
datatype sum(datatype a, datatype b){
    return a + b;
}


int main(){

    cout << sum(4,5) << endl;
    cout << sum(3.5 , 2.2) << endl;
    
    return 0;
}