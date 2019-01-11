#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string>
#include <vector>

class Artwork {
    //PRIVATE ATTRIBUTES
    unsigned int year;
    string artistName;
    string artName;

public:
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
    string getName() {
        return artistName;
    }
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
    }

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
        cout << art.getName() << endl;
        cout << "Inserted new Art" << endl;
        return true;
    }

    bool sell_artwork(SoldArtwork& sold){
        for (int i = 0; i < artInfo.size(); ++i) {
            if (static_cast<Artwork>(sold) == artInfo[i]) {
                artInfo.erase(artInfo.begin() + i);
            }
        }

        soldInfo.push_back(sold);
        cout << "Artwork Sold" << endl;
        return true;
    }

    //OVERLOADING OPERATOR
    bool operator==(const ArtCollection& artCollect) {
        int counter = 0;

        if ((artInfo.size() == artCollect.artInfo.size()) && (soldInfo.size() ==  artCollect.soldInfo.size())) {
            for (int i = 0; i < artInfo.size(); ++i) {
                for (int j = 0; j < artCollect.artInfo.size(); ++j){
                    if (!(artInfo[i] == artCollect.artInfo[j])) {
                        cout << "Not the same" << endl;
                        return false;
                    }
                }
            }

            for (int i = 0; i < soldInfo.size(); ++i) {
                for (int j = 0; j < artCollect.soldInfo.size(); ++j){
                    if (!(soldInfo[i] == artCollect.soldInfo[j])) {
                        cout << "Not the same" << endl;
                        return false;
                    }
                }
            }
            cout << "They are the same" << endl;
            return true;
        }
        cout << "Not the same" << endl;
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

    cout << "New Collection Created" << endl;
    return nCollection;
}

int main() {

    //QUICK TESTING 
    Artwork art1(0, "Tosh", "yea");
    Artwork art2(1233, "no", "yes");
    SoldArtwork art3(art2, 23, "43 Ho", "syde");

    ArtCollection check;
    check.insert_artwork(art2);
    check.insert_artwork(art1);

};