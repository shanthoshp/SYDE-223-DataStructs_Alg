#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string>
#include <vector>
#include <cassert>

class Artwork {

public:
    //PUBLIC ATTRIBUTES
    unsigned int year;
    string artistName;
    string artName;

    //DEFAULT CONSTRUCTOR
    Artwork() {
        year = 0;
        artistName = "";
        artName = "";
    }

    //PARAMETRIC CONSTRUCTOR
    Artwork(unsigned int nYear, string nArtistName, string nArtName) {
        year = nYear;
        artistName = nArtistName;
        artName = nArtName;
    }

    //OVERLOADING OPERATOR
    bool operator==(const Artwork& newArt) {
        bool sameArtwork = true;
        sameArtwork = sameArtwork && year == newArt.year;
        sameArtwork =  sameArtwork && artistName == newArt.artistName;
        sameArtwork = sameArtwork && artName == newArt.artName;

        return sameArtwork;
    }

    //GETTER FUNCTIONS FOR TESTING
    string getArtistName() {
        return artistName;
    };
};

class SoldArtwork : public Artwork {
    //PRIVATE ATTRIBUTES
    double saleAmount;
    string customerAddress;
    string customerName;

public:
    //DEFAULT CONSTRUCTOR
    SoldArtwork() {
        saleAmount = 0;
        customerAddress = "";
        customerName = "";
    }

    //PARAMETRIC CONSTRUCTOR
    SoldArtwork(Artwork& newArt, double nSaleAmount, string nCustomerAddress, string nCustomerName) {
        saleAmount = nSaleAmount;
        customerAddress = nCustomerAddress;
        customerName = nCustomerName;
        year = newArt.year;
        artistName = newArt.artistName;
        artName = newArt.artName;
    };


    //OVERLOADING OPERATOR
    bool operator==(const SoldArtwork& soldArt) {
        bool sold = true;
        sold = sold && saleAmount == soldArt.saleAmount;
        sold =  sold && customerAddress == soldArt.customerAddress;
        sold = sold && customerName == soldArt.customerName;
        return sold;
    }
};

class ArtCollection {
    //PRIVATE ATTRIBUTES
    vector <Artwork> artInfo;
    vector <SoldArtwork> soldInfo;

public:
    //SERVICE FUNCTIONS
    bool insert_artwork(Artwork& art){
        for (int i = 0; i < artInfo.size(); ++i) {
            if (art == artInfo[i]) {
                cout << "Duplicate Art Entry! Not added to vector" << endl;
                cout << "----------------------------------------- " << endl;
                return false;
            }
        }

        artInfo.push_back(art);
        cout << "Artist Name: " << art.getArtistName() << endl;
        cout << "Inserted new Art -> Vector Size: " << artInfo.size() << endl;
        cout << "----------------------------------------- " << endl;
        return true;
    }

    bool sell_artwork(SoldArtwork& sold){
        bool checkArt = false;

        for (int i = 0; i < artInfo.size(); ++i) {
            if (static_cast<Artwork>(sold) == artInfo[i]) {
                artInfo.erase(artInfo.begin() + i);
                cout << "Artwork removed from Art Vector -> Vector Size: " << artInfo.size() << endl;
                checkArt = true;
            }
        }

        if (checkArt) {
            soldInfo.push_back(sold);
            cout << "Artwork Sold -> Sold Vector Size: " << soldInfo.size() << endl;
            cout << "----------------------------------------- " << endl;
            return true;
        }

        cout << "Art is not apart of collection! Can not sell!" << endl;
        return false;

    }
    
    vector <Artwork> getArtInfo(){  
		return artInfo;
	}
    

    //OVERLOADING OPERATOR
    bool operator==(const ArtCollection& artCollect) {
        int artInfoCounter = 0;
        int soldInfoCounter = 0;

        cout << "////////////////////////////////////" << endl;
        cout << "Current Collection Art Vector size: " << artInfo.size() << endl;
        cout << "Current Collection Art Sold Vector size: " << soldInfo.size() << endl;
        cout << "////////////////////////////////////" << endl;


        cout << "////////////////////////////////////" << endl;
        cout << "New Collection Art Vector size: " << artCollect.artInfo.size() << endl;
        cout << "New Collection Art Sold Vector size: " << artCollect.soldInfo.size() << endl;
        cout << "////////////////////////////////////" << endl;


        if ((artInfo.size() == artCollect.artInfo.size()) && (soldInfo.size() ==  artCollect.soldInfo.size())) {
            for (int i = 0; i < artInfo.size(); ++i) {
                for (int j = 0; j < artCollect.artInfo.size(); ++j){
                    if (artInfo[i] == artCollect.artInfo[j]) {
                        artInfoCounter++;
                        cout << artInfoCounter << " : " << artInfo.size() << endl;
                    }
                }
            }

            for (int i = 0; i < soldInfo.size(); ++i) {
                for (int j = 0; j < artCollect.soldInfo.size(); ++j){
                    if (soldInfo[i] == artCollect.soldInfo[j]) {
                        soldInfoCounter++;
                        cout << soldInfoCounter << " : " << soldInfo.size() << endl;
                    }
                }
            }

            if ((artInfoCounter == artInfo.size() && soldInfoCounter == soldInfo.size())) {
                cout << "They are the same collection" << endl;
                return true;
            }

            cout << "Not the same collection" << endl;
            return false;
        }
        cout << "Not the same collection" << endl;
        return false;
    }

    friend ArtCollection operator+(const ArtCollection& artCollect1, const ArtCollection& artCollect2);
};

ArtCollection operator+(const ArtCollection& artCollect1, const ArtCollection& artCollect2) {
    //NEW VECTORS
    vector <Artwork> nArtInfo;
    vector <SoldArtwork> nSoldInfo;

    ArtCollection nCollection;

    nCollection.artInfo = artCollect1.artInfo;
    nCollection.soldInfo = artCollect1.soldInfo;

    for (int i = 0; i < artCollect2.artInfo.size(); ++i) {
        nCollection.artInfo.push_back(artCollect2.artInfo[i]);
    }

    for (int i = 0; i < artCollect2.soldInfo.size(); ++i) {
        nCollection.soldInfo.push_back(artCollect2.soldInfo[i]);
    }

    cout << "////////////////////////////////////" << endl;
    cout << "New Art Collection Created" << endl;
    cout << "New Collection Art Vector Size : " << nCollection.artInfo.size() << endl;
    cout << "New Collection Art Sold Vector Size : " << nCollection.soldInfo.size() << endl;
    cout << "////////////////////////////////////" << endl;

    return nCollection;
}


void test_scenario1() { // test duplicate insert
    Artwork art1(1999, "Art1", "SYDE223");
    Artwork art2(2019, "Art2", "SYDE223");
    Artwork art3(2019, "Art3", "SYDE223");
    Artwork art3Copy(2019, "Art3", "SYDE223");
    
    ArtCollection test1;
    //Inserting
    test1.insert_artwork(art1);
    test1.insert_artwork(art2);
    test1.insert_artwork(art3);
    
	// example: use assertions to check function insert_artwork
	assert(test1.getArtInfo().size() == 3);
	    
    test1.insert_artwork(art3Copy);
	
	assert(test1.getArtInfo().size() == 3);

	cout<< "Test1 Passed: duplicate detected correctly" << endl;
	
	
}

int main() {
	test_scenario1();

   /* //QUICK TESTING
    Artwork art1(1999, "Art1", "SYDE223");
    Artwork art2(2019, "Art2", "SYDE223");
    Artwork art3(2019, "Art3", "SYDE223");
    Artwork art3Copy(2019, "Art3", "SYDE223");
	
    SoldArtwork soldArt1(art1, 100, "Sold", "Sold");
    SoldArtwork soldArt1Copy(art1, 100, "NA", "NA");
    SoldArtwork soldArt2(art2, 100, "Sold", "Sold");


    ArtCollection test1;
    //Inserting
    test1.insert_artwork(art1);
    test1.insert_artwork(art1);
    test1.insert_artwork(art2);
    test1.insert_artwork(art3);
    test1.insert_artwork(art3Copy);

    //Selling
    test1.sell_artwork(soldArt1);
    test1.sell_artwork(soldArt1Copy);
    test1.sell_artwork(soldArt2);

    //New ArtCollection
    ArtCollection test2;
    //Inserting
    test2.insert_artwork(art1);
    test2.insert_artwork(art2);
    test2.insert_artwork(art3);
    test2.insert_artwork(art3Copy);

    //Selling
    test2.sell_artwork(soldArt2);
    test2.sell_artwork(soldArt1Copy);
    test2.sell_artwork(soldArt2);

    //Testing overloading + & ==
    
    test1 == test2;
    test1 + test2;*/
    
};

