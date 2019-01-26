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
public:
    bool test_constructor1();

    bool test_constructor2();

    bool test_constructor3();
 
    bool test_resize();
    bool test_removal();

	bool test_equal();
	bool test_add();
	bool test_subtract();
	bool test_multiply();
	bool test_derivative();
	
	bool test_print();
	
	void run();


};


#endif //LAB_1_LAB1_POLYNOMIAL_H
