//SHANTHOSH PUSHPARJAH 20710273 && TANJOT PANESAR 20727567 
#ifndef LAB_1_LAB1_POLYNOMIAL_H
#define LAB_1_LAB1_POLYNOMIAL_H

class Polynomial{
    //PRIVATE ATTRIBUTES
    vector<int> data;
    int data_size;

public:
    Polynomial();
    //PURPOSE: Default Constructor 
    //INPUT: No inputs
    //RETURN: Assigns random values from -1000 to 1000 to vector data attribute and assigns a random value from 0 to 1000 to data_size attribute

    Polynomial(vector<int> A, int size);
    //PURPOSE: Parametric Constructor
    //INPUT: Takes in two inputs: int vector data type and an int data type
    //RETURN: Assign int values to vector data attribute and a int value to data_size attribute

    Polynomial(string fileName);
    //PURPOSE: Parametric Constructor used to navigate to a external file
    //INPUT: string filename
    //RETURN: Assigns int values to data_size and vector data attributes

    //DESTRUCTOR
    ~Polynomial();

	  vector<int> getData();
    //PURPOSE: Getter method - used for testing purposes
    //INPUT: No inputs
    //RETURN: Returns the int vector data attribute

	  int getDataSize();
    //PURPOSE: Getter method - used for testing purposes
    //INPUT: No inputs
    //RETURN: Returns the data_size attribute
 
    void makeVectorSizeSame(Polynomial& target);
    //PURPOSE: Helper method - purpose to make two vectors the same size
    //INPUT: Polynomial object
    //RETURN: Ensures current data vector and the Polynomial objects data vector is the same size and updates data_size values;

    bool operator==(const Polynomial& target);
    //PURPOSE: To check if two Polynomial objects are the same
    //INPUT: Polynomial object
    //RETURN True if same and false if not

    Polynomial operator+(const Polynomial& target);
    //PURPOSE: To add two Polynomial objects
    //INPUT: Polynomial object
    //RETURN: Returns a new Polynomial object of the two added Polynomial objects and an update polynomial size

    Polynomial operator-(const Polynomial& target);
    //PURPOSE: To subtract two Polynomial objects
    //INPUT: Polynomial object
    //RETURN: Returns a new Polynomial object of the two subtracted Polynomial objects and an update polynomial size

    Polynomial operator*(const Polynomial& target);
    //PURPOSE: To multiply two Polynomial objects
    //INPUT: Polynomial object
    //RETURN: Returns a new Polynomial object of the two mulitplied Polynomial objects and an update polynomial size

    Polynomial derivative();
    //PURPOSE: To find the derivative of the polynomial
    //INPUT: No input
    //RETURN: Returns the derviative of the Polynomial

    //PRINTS POLYNOMIAL
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
  vector<int> new1 = {5,6,7,8,3,5,7,2,0,0,0};
  vector<int> new2 = {45,6,734,64,2,0,0};
  vector<int> multi1 = {1,-3,5,-7,8,0,0,0};
  vector<int> multi2 = {45,23,-9,6};
  vector<int> same1 = {1,2,3,5,6,7,7,8,9,9,-67,0,0,0,0,0,0};
  vector<int> same2 = {1,2,3,5,6,7,7,8,9,9,-67};
  vector<int> same3 = {1,2,3,5,6,7,0,8,9,9,-67,0,0,0,0,0,0};

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
