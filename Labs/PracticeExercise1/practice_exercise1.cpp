#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string>
#include <vector>
#include <cassert>

//SYDE 223 - PracticeExercise1 - Shanthosh Pushparajah & Tanjot Panesar

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
                return false;
            }
        }

        artInfo.push_back(art);
        return true;
    }

    bool sell_artwork(SoldArtwork& sold){
        bool checkArt = false;

        for (int i = 0; i < artInfo.size(); ++i) {
            if (static_cast<Artwork>(sold) == artInfo[i]) {
                artInfo.erase(artInfo.begin() + i);
                checkArt = true;
            }
        }

        if (checkArt) {
            soldInfo.push_back(sold);
            return true;
        }

        return false;

    }
    
    //GETTERS
    vector <Artwork> getArtInfo(){  
		return artInfo;
	}

	vector <SoldArtwork> getSoldInfo(){  
		return soldInfo;
	}
    

    //OVERLOADING OPERATOR
    bool operator==(const ArtCollection& artCollect) {
        int artInfoCounter = 0;
        int soldInfoCounter = 0;

        if ((artInfo.size() == artCollect.artInfo.size()) && (soldInfo.size() ==  artCollect.soldInfo.size())) {
            for (int i = 0; i < artInfo.size(); ++i) {
                for (int j = 0; j < artCollect.artInfo.size(); ++j){
                    if (artInfo[i] == artCollect.artInfo[j]) {
                        artInfoCounter++;
                    }
                }
            }

            for (int i = 0; i < soldInfo.size(); ++i) {
                for (int j = 0; j < artCollect.soldInfo.size(); ++j){
                    if (soldInfo[i] == artCollect.soldInfo[j]) {
                        soldInfoCounter++;
                    }
                }
            }

            if ((artInfoCounter == artInfo.size() && soldInfoCounter == soldInfo.size())) {
                return true;
            }
            return false;
        }
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

    return nCollection;
}

///////////
//TESTING//
///////////
void test_insertion() {
	//Init instances
	Artwork art1(1999, "Art1", "SYDE223");
    Artwork art2(2019, "Art2", "SYDE223");
	Artwork art3(2019, "Art3", "SYDE223");

	//New collection
    ArtCollection test1;
		    
	//Insert
    test1.insert_artwork(art1);
    test1.insert_artwork(art2);
    test1.insert_artwork(art3);
    
	// TESTCASE 1: use assertions to check function insert_artwork
	assert(test1.getArtInfo().size() == 3);
	cout<< "Test Case 1 Passed: inserts correctly" << endl;	
}

void test_insertion_duplicate() {
	//Init instances
	Artwork art1(1999, "Art1", "SYDE223");
    Artwork art2(2019, "Art2", "SYDE223");
	Artwork art3(2019, "Art3", "SYDE223");
    Artwork art3Copy(2019, "Art3", "SYDE223");	    
	
	//New collection
    ArtCollection test1;
		    
	//Insert
    test1.insert_artwork(art1);
    test1.insert_artwork(art2);
    test1.insert_artwork(art3);
    test1.insert_artwork(art3Copy); //duplicate
    
	// TESTCASE 2: use assertions to check if duplicate is added to using insert_artwork
	assert(test1.getArtInfo().size() == 3);	//check before copy is added  
    test1.insert_artwork(art3Copy);	
	assert(test1.getArtInfo().size() == 3);	//check after copy is added 
	cout<< "Test Case 2 Passed: insert and duplicate detected correctly" << endl;	
}

void test_sell_artwork() {
	//Init instances
	Artwork art1(1999, "Art1", "SYDE223");
    Artwork art2(2019, "Art2", "SYDE223");
	Artwork art3(2019, "Art3", "SYDE223");
	SoldArtwork soldArt1(art1, 100, "Sold", "Sold");
    SoldArtwork soldArt2(art2, 100, "Sold", "Sold");
	//New collection
    ArtCollection test1;
		    
	//Insert
    test1.insert_artwork(art1);
    test1.insert_artwork(art2);
    test1.insert_artwork(art3);
    
	//TESTCASE 3: use assertions to check function sold_artwork
    test1.sell_artwork(soldArt1);
    test1.sell_artwork(soldArt2);

	assert(test1.getArtInfo().size() == 1 && test1.getSoldInfo().size() ==2);
	cout<< "Test Case 3 Passed: sold 2/3 artworks correctly" << endl;
}

void test_sell_artwork_duplicate(){
	//Init instances
	Artwork art1(1999, "Art1", "SYDE223");
    Artwork art2(2019, "Art2", "SYDE223");
	Artwork art3(2019, "Art3", "SYDE223");
    Artwork art3Copy(2019, "Art3", "SYDE223");	    
	SoldArtwork soldArt1(art1, 100, "Sold", "Sold");
	SoldArtwork soldArt1Copy(art1, 100, "NA", "NA");
    SoldArtwork soldArt2(art2, 100, "Sold", "Sold");
	//New collection
    ArtCollection test1;
    
    //Insert
    test1.insert_artwork(art1);
    test1.insert_artwork(art2);
    test1.insert_artwork(art3);

    
	//TESTCASE 4: use assertions to check function sold_artwork
    
    test1.sell_artwork(soldArt1);
    test1.sell_artwork(soldArt1Copy); //duplicate
    test1.sell_artwork(soldArt2);
    
	assert(test1.getArtInfo().size() == 1 && test1.getSoldInfo().size() ==2);
	
	cout<< "Test Case 4 Passed: sold 2/3 artworks correctly, duplicate avoided" << endl;
}
void test_operators() { 
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

    
	// TESTCASE 5: use assertions to check function sell_artwork	
		assert(test1.getSoldInfo().size() == 2);
		cout<< "Test Case 5 Passed: SoldArtWork contains more artworks now" << endl;

	//TESTCASE 6: == operator for ArtCollection
	    assert(test1 == test2);
	    cout<< "Test Case 6 Passed: Two collections exactly equal to each other" << endl;

	//TESTCASE 7: + operator for ArtCollection		
		ArtCollection sum = test1 + test2;
	   	assert(sum.getArtInfo().size() == 2 && sum.getSoldInfo().size() == 4); 	// collection = artwork (1+1=2) & soldwork (2+2=4)
	    cout<< "Test Case 7 Passed: Two collections added together" << endl;
}

int main() {
	test_insertion();
	test_insertion_duplicate();
	test_sell_artwork();
	test_sell_artwork_duplicate();
	test_operators();
};

