#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string>

class Toy {
    //PRIVATE
    string shape;
    string colour;
    bool speak;

public:
    //DEFAULT CONSTRUCTOR
    Toy() {
        speak = true;
        colour = " ";
        speak = " ";
    }

    //PARAMETRIC CONSTRUCTOR
    Toy(bool nSpeaker, string nColour, string nShape) {
        speak = nSpeaker;
        colour = nColour;
        shape = nShape;
    }

    //OVERLOAD FUNCTION
    bool operator==(Toy& value){
        bool sameToy = true;
        sameToy = sameToy && (speak == value.speak);
        sameToy = sameToy && (colour == value.colour);
        sameToy = sameToy && (shape == value.shape);
        cout << sameToy << endl;
    }
};

class ToyCollection : public Toy {
    //PRIVATE
    int size();



};


int main() {
    Toy toy1(true, "Green", "Circle");
    Toy toy2(true, "Green", "Circle");
    toy1 == toy2;
}