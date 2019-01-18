#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string>
#include <vector>
#include <cassert>
#include "lab1.polynomial.h" // header in local directory
#include <iomanip>

using namespace std;

//DEFAULT
Polynomial :: Polynomial(){
	
}

//PARAMETRIC
Polynomial :: Polynomial(int A[], int size) 
  : polynomialArray(a), polynomialSize (size), second(s)
{

}

//PARAMETRIC
Polynomial :: Polynomial(string filepath) 
  : fileName(filepath)
{

}
 
//DESTRUCTOR
Polynomial::~Polynomial(void) {

}	
 
bool Polynomial::operator==(constPerson& target) const{
	
	return boolean;
}

//== OPERATOR OVERLOAD
bool Polynomial::operator==(constPerson& target) const{
	
	return boolean;
}

//+ OPERATOR OVERLOAD
bool Polynomial::operator+(constPerson& target) const{
	
	return boolean;
}

//- OPERATOR OVERLOAD
bool Polynomial::operator-(constPerson& target) const{
	
	return boolean;
}

//* OPERATOR OVERLOAD
bool Polynomial::operator*(constPerson& target) const{
	
	return boolean;
}

//PRINT METHOD
void Polynomial :: print() const
{
    cout << setw(2) << setfill('0') << hour << ":"
	<< setw(2) << setfill('0') << minute << ":"
 	<< setw(2) << setfill('0') << second << "\n";	
 
}
 
//DERIVATIVE METHOD
void Polynomial :: derivative() const
{
 
}
 

int main(){
	
}
