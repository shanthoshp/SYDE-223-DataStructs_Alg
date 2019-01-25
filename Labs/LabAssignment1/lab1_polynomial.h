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



#endif //LAB_1_LAB1_POLYNOMIAL_H
