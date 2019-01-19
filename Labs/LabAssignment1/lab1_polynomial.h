//
// Created by Shanthosh Pushparajah on 2019-01-18.
//

#ifndef LAB_1_LAB1_POLYNOMIAL_H
#define LAB_1_LAB1_POLYNOMIAL_H

class Polynomial {

    //PRIVATE ATTRIBUTES
    vector<int> data;
    int data_size;

public:

    //DEFAULT CONSTRUCTOR
    Polynomial();

    //PARAMETRIC CONSTRUCTOR
    Polynomial(int A[], int size);

    //PARAMETRIC CONSTRUCTOR
    Polynomial(string fileName);

    //DESTRUCTOR
    ~Polynomial();

    //BOOL OVERLOADING
    bool operator==(const Polynomial& target);

    //ADDITION OPERATOR
    bool operator+(const Polynomial& target);

    //SUBTRACTION OPERATOR
    bool operator-(const Polynomial& target);

    //MULTIPLICATION OPERATOR
    bool operator*(const Polynomial& target);

    //DERIVATIVE
    Polynomial derivative();

    //PRINT
    void print();

};



#endif //LAB_1_LAB1_POLYNOMIAL_H
