#ifndef TIME_H
#define TIME_H

class Polynomial {
	int* data;
	int data_size;
	
	Polynomial(int A[], int size){
		data = new int[size];
	}
	
	~Polynomial(){
		delete []data;
	}
};
 
#endif
