#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string>
#include <cassert>
#include <random>
#include <fstream>
#include <iomanip>
#include "lab1_polynomial.h" // header in local directory



//DEFAULT CONSTRUCTOR
Polynomial :: Polynomial() {
    random_device generator;
    mt19937 type(generator());
    uniform_int_distribution<> size(0, 1000);
    uniform_int_distribution<> coefficients(-1000, 1000);

    data_size = size(type);

    data.resize(data_size);

    for (int i = 0; i < data_size; i++) {
        data[i] = coefficients(type);
    }
}

//2 ARGUMENT PARAMETRIC CONSTRUCTOR
Polynomial :: Polynomial(int A[], int size) {
    data_size = size;
    data.resize(data_size);

    for (int i = 0; i < data_size; i++) {
        data[i] = A[i];
    }

}

//1 ARGUMENT PARAMETRIC CONSTRUCTOR
Polynomial :: Polynomial(string filename){
    ifstream file;
    file.open(filename);

    if(!file.is_open()) {
        cout << "Error -> Cannot open file" << endl;
    }

    string getValue;
    getline(file, getValue);
    data_size = stoi(getValue);

    while (getline(file, getValue)) {
        if (getValue.size() > 0) {
            data.push_back(stoi(getValue));
        }
    }
}

//DESTRUCTOR
Polynomial :: ~Polynomial() {}

//bool Polynomial::operator==(constPerson& target) const{
//
//    return boolean;
//}
//
////== OPERATOR OVERLOAD
//bool Polynomial::operator==(constPerson& target) const{
//
//    return boolean;
//}
//
////+ OPERATOR OVERLOAD
//bool Polynomial::operator+(constPerson& target) const{
//
//    return boolean;
//}
//
////- OPERATOR OVERLOAD
//bool Polynomial::operator-(constPerson& target) const{
//
//    return boolean;
//}
//
////* OPERATOR OVERLOAD
//bool Polynomial::operator*(constPerson& target) const{
//
//    return boolean;
//}
//
////PRINT METHOD
//void Polynomial :: print() const
//{
//    cout << setw(2) << setfill('0') << hour << ":"
//    << setw(2) << setfill('0') << minute << ":"
//    << setw(2) << setfill('0') << second << "\n";
//
//}
//
////DERIVATIVE METHOD
//void Polynomial :: derivative() const
//{
//
//}


int main(){
    int q[] = {3,4,4};
    Polynomial();
    Polynomial(q, 3);
}
