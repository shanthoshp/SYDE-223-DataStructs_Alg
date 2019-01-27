//
// Created by Shanthosh Pushparajah on 2019-01-18.
//

#ifndef LAB_1_LAB1_POLYNOMIAL_H
#define LAB_1_LAB1_POLYNOMIAL_H

class Polynomial{
    //PRIVATE ATTRIBUTES
    vector<int> data;
    int data_size;
public:

    //DEFAULT CONSTRUCTOR
    Polynomial();

    //PARAMETRIC CONSTRUCTOR
    Polynomial(vector<int> A, int size);

    //PARAMETRIC CONSTRUCTOR
    Polynomial(string fileName);

    //DESTRUCTOR
    ~Polynomial();

	//GETTERS
	vector<int> getData();
	int getDataSize();
 
    //HELPER METHODS
    void makeVectorSizeSame(Polynomial& target);
    void removeExtraZeros(Polynomial& target);

    //BOOL OVERLOADING
    bool operator==(const Polynomial& target);

    //ADDITION OPERATOR
    Polynomial operator+(const Polynomial& target);

    //SUBTRACTION OPERATOR
    Polynomial operator-(const Polynomial& target);

    //MULTIPLICATION OPERATOR
    Polynomial operator*(const Polynomial& target);

    //DERIVATIVE
    Polynomial derivative();

    //PRINT
    void print();

};


class PolynomialTest : public Polynomial{
private:
	vector<int> data1 = {1,2,4,3, 0, 0 ,0};
    vector<int> data2 = {1,2,4,3,0};
    vector<int> data3 = {0,0,2,0,1};
    vector<int> data4 = {1,0,0,2,5};
    vector<int> data5 = {3,2};
    vector<int> data6 = {3};
    vector<int> data7 = {3,2};
public:
    bool test_constructor1();

    bool test_constructor2();

    bool test_constructor3();

	bool test_equal();
	bool test_add();
	bool test_subtract();
	bool test_multiply();
	bool test_derivative();
	
	bool test_print();
	
	void run();


};


#endif //LAB_1_LAB1_POLYNOMIAL_H
