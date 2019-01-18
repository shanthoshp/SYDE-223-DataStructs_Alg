#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string>
#include <random>
#include <cassert>
#include "lab1_polynomial.h" // header in local directory
#include <iomanip>

using namespace std;

//DEFAULT CINSTRUCTOR
Polynomial :: Polynomial() {

    //<RANDOM>> Lib functions
    default_random_engine generator;
    uniform_int_distribution<int> size(0,1000);
    uniform_int_distribution<int> coefficients(-1000,1000);
    

}

////PARAMETRIC
//Polynomial :: Polynomial(int A[], int size) {
//
//}

////PARAMETRIC
//Polynomial :: Polynomial(string filepath): fileName(filepath)
//{
//
//}


//
////DESTRUCTOR
//Polynomial::~Polynomial(void) {
//
//}
//
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
    
}
