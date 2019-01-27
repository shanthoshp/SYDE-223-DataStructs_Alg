#include <iostream>
#include <stdlib.h>
#include <string>
#include <cassert>
#include <random>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
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
    if (size <= 0 || A.size() == 0) {
        data_size = 0;
        data.resize(data_size);
    } else {
      data_size = size;
      data.resize(data_size);
      for (int i = 0; i < data_size; i++) {
        data[i] = A[i];
      }
    }
}

//PARAMETRIC CONSTRUCTOR -> FILENAME
Polynomial :: Polynomial(string filename) {
    ifstream file;
    file.open(filename.c_str());
    int poly_size = 0;
    int i = 0;

    if (!file.is_open()) {
        cout << " Error -> Cannot open file" << endl;
    } else {
        file >> poly_size;
        poly_size = abs(poly_size);
        data_size = poly_size;
        data.resize(data_size);

        while (!file.eof()) {
            file >> data[i];
            i++;
        }
    }
}

//DESTRUCTOR
Polynomial :: ~Polynomial() {}

//GETTERS
vector<int> Polynomial :: getData(){
	return data;
}

int Polynomial :: getDataSize(){
	return data_size;
}

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
    temp.data_size = target.data_size;

    removeExtraZeros(temp);

    if (data.size() == temp.data.size()) {
        for (int i = 0; i < data_size; i++) {
            if (data[i] == temp.data[i]) {
                counter++;
            }
        }
    }

    if (counter == data.size()) {
        return true;
    } else {
        return false;
    }
}

//+ OPERATOR OVERLOAD
Polynomial Polynomial :: operator+(const Polynomial& target) {
    Polynomial temp;
    temp.data = target.data;
    temp.data_size = target.data_size;

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
    temp.data_size = target.data_size;

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
	Polynomial poly1(data3, data3.size());
	assert(poly1.getDataSize() == 5 ); //5 elements should be in vector
	return true;
}

//default constructor testing
bool PolynomialTest :: test_constructor2() { 
	Polynomial poly1;
	assert(getDataSize() <= 1000); // less than 1000 
	for(int i = 0; i < getDataSize(); i++){
		assert(poly1.getData()[i] > -1000 && poly1.getData()[i] < 1000); //in between -1000 to 1000 range for coefficients
	}
    return true;
}

bool PolynomialTest :: test_constructor3(){  
	Polynomial poly1("polynomial.txt");
	Polynomial poly2("corruptedPolynomial.txt");
	
	assert(poly1.getDataSize() == 3); //reading size from proper submitted data through textfile
	assert(poly2.getData().size() == 3); //checking if corrupted data is submitted (size 4, and more or less inputs such ass only 2 inputs or 6 inputs)
	poly2.print(); //printing to verify "0" coefficients are assigned to missing indicies if corrupted data.
	return true;
}


bool PolynomialTest :: test_equal(){
	Polynomial poly1(data5, data5.size());
	Polynomial poly2(data7, data7.size());
	Polynomial poly3(data1, data1.size());
	Polynomial poly4(data2, data2.size());
	assert(poly1 == poly2);
	assert(poly3 == poly4);
	return true;	
}

bool PolynomialTest ::  test_add(){
  	Polynomial poly1(data3, data3.size());
    Polynomial poly2(data2, data2.size());
    poly1 = poly1 + poly2;
    assert(poly1.getData()[2] == 6); //Coefficient of 3rd degree addition should be 6
	return true;	
}

bool PolynomialTest ::  test_subtract(){
	Polynomial poly1(data3, data3.size());
    Polynomial poly2(data2, data2.size());
    poly1 = poly1 - poly2;
    assert(poly1.getData()[2] == -2); //Coefficient of 3rd degree subtraction should be 4
	return true;	
}


bool PolynomialTest ::  test_multiply(){
	Polynomial poly1(data5, data5.size());
	Polynomial poly2(data6, data6.size());
    poly1 = poly1 * poly2;
    assert(poly1.getData()[0] == 9 ); //Coefficient of 3rd degree multiplication should be 9
	return true;	
}


bool PolynomialTest ::  test_derivative(){
	Polynomial poly1(data5, data5.size());
    poly1 = poly1.derivative();
    assert(poly1.getData()[0] == 2); //test if derivative coefficient of now the constant place is 2.
	return true;	
}

bool PolynomialTest ::  test_print(){
	Polynomial poly1(data5, data5.size());
	poly1.print();
	return true;	
}

void PolynomialTest :: run(){
	if(test_constructor1()) cout<<"Constructor 1 Tested"<< endl;
	if(test_constructor2()) cout<<"Constructor 2 Tested"<< endl;
	if(test_constructor3()) cout<<"Constructor 3 Tested"<< endl;
	test_equal();
	test_add();
	test_subtract();
	test_multiply();
	test_derivative();
	test_print();
}


int main(){
    PolynomialTest p;
    p.run();
}

