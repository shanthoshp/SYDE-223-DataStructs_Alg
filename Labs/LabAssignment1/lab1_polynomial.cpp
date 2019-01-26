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
Polynomial :: Polynomial(vector<int> A, int size) {
    data_size = size;
    data.resize(data_size);

    for (int i = 0; i < data_size; i++) {
        data[i] = A[i];
    }
}

//PARAMETRIC CONSTRUCTOR -> FILENAME
Polynomial :: Polynomial(string filename){
    ifstream file;
    file.open(filename.c_str());

    if(!file.is_open()) {
        cout << "Error -> Cannot open file" << endl;
    } else {
        string getValue;
        getline(file, getValue);
        data_size = stoi(getValue);

        while (getline(file, getValue)) {
            if (getValue.size() > 0) {
                data.push_back(stoi(getValue));
            }
        }
    }
}

//DESTRUCTOR
Polynomial :: ~Polynomial() {}




//HELPER METHODS
void Polynomial :: makeVectorSizeSame(Polynomial &target) {
    int size = abs(data_size - target.data_size);

    if (size > 0) {
        for (int i = 0; i < size; i++) {
            if (data_size < target.data_size) {
                data.push_back(0);
            } else if (target.data_size < data_size) {
                target.data.push_back(0);
            }
        }
    }

    target.data_size = target.data.size();
}

void Polynomial :: removeExtraZeros(Polynomial &target) {
    int size = abs(data_size - target.data_size);

    if (size > 0) {
        for (int i = 0; i < size; i++) {
            if ((data_size > target.data_size) && (data[data_size - i - 1] == 0)) {
                data.pop_back();
            } else if ((target.data_size > data_size) && (target.data[target.data_size - i - 1] == 0)) {
                target.data.pop_back();
            }
        }
    }

    target.data_size = target.data.size();
}

//== OPERATOR OVERLOAD
bool Polynomial :: operator==(const Polynomial& target) {
    int counter = 0;
    Polynomial temp;
    temp.data = target.data;
    temp.data_size = temp.data_size;

    removeExtraZeros(temp);

    if (data.size() == temp.data.size()) {
        for (int i = 0; i < data_size; i++) {
            if (data[i] == temp.data[i]) {
                counter++;
            }
        }
    }

    if (counter == data.size()) {
        cout << "true" << endl;
        return true;
    } else {
        cout << "false" << endl;
        return false;
    }
}

//+ OPERATOR OVERLOAD
Polynomial Polynomial :: operator+(const Polynomial& target) {
    Polynomial temp;
    temp.data = target.data;
    temp.data_size = temp.data_size;

    makeVectorSizeSame(temp);

    for (int i = 0; i < temp.data_size; i++) {
        temp.data[i] += data[i];
    }


    return temp;
}

//- OPERATOR OVERLOAD
Polynomial Polynomial :: operator-(const Polynomial& target) {
    Polynomial temp;
    temp.data = target.data;
    temp.data_size = temp.data_size;

    makeVectorSizeSame(temp);

    for (int i = 0; i < temp.data_size; i++) {
        temp.data[i] = data[i] - temp.data[i];
    }


    return temp;
}

//* OPERATOR OVERLOAD
Polynomial Polynomial :: operator*(const Polynomial& target) {
    Polynomial temp;
    temp.data = target.data;
    temp.data_size = target.data_size;

    makeVectorSizeSame(temp);

    vector<int> multiply(2 * temp.data_size, 0);

    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < temp.data_size; j++) {
            multiply[i+j] += (data[i] * temp.data[j]);
        }
    }

    temp.data_size = multiply.size();
    temp.data = multiply;

    return temp;
}

//DERIVATIVE METHOD
Polynomial Polynomial :: derivative() {
    vector<int> derivative(data_size, 0);
    for (int i = 1; i < data_size; i++) {
        derivative[i - 1] = data[i] * i;
    }

    Polynomial temp;
    temp.data = derivative;
    temp.data_size = derivative.size();

    return temp;
}

//PRINT METHOD
void Polynomial :: print() {

    for (int j = data_size - 1; j >= 0; j--) {
        if (data[j] == 0) {
            if (data[j - 1] != 0 && j != 0) {
                cout << "+ ";
            }
        } else{
            cout << data[j] << "x^" << j << " ";
            if (data[j - 1] != 0 && j != 0) {
                cout << "+ ";
            }
        }
    }
    cout << endl;
}


bool PolynomialTest :: test_constructor1(){
    cout<<"it worked" << endl;
    return true;

}
bool PolynomialTest :: test_constructor2(){
    return true;
}

bool PolynomialTest :: test_constructor3(){      
	return true;
}
bool PolynomialTest ::  test_resize(){
	return true;
}

bool PolynomialTest ::  test_removal(){
	return true;	
}

bool PolynomialTest ::  test_equal(){
	return true;	
}

bool PolynomialTest ::  test_add(){
	return true;	
}

bool PolynomialTest ::  test_subtract(){
	return true;	
}


bool PolynomialTest ::  test_multiply(){
	return true;	
}


bool PolynomialTest ::  test_derivative(){
	return true;	
}

bool PolynomialTest ::  test_print(){
	return true;	
}

void PolynomialTest :: run(){
	
}


int main(){
    vector<int> data1 = {1,2,4,3, 0, 0 ,0};
    vector<int> data2 = {1,2,4,0,0};
    vector<int> data3 = {0,0,2,0,1};
    vector<int> data4 = {1,0,0,2, 5};
    Polynomial t(data3, data3.size());
    Polynomial s(data4, data4.size());
    s.operator==(t);
    s.operator+(t);
    s.operator-(t);
    s.operator*(t);
    s.derivative();
    s.print();

    Polynomial("polynomial.txt");

}
