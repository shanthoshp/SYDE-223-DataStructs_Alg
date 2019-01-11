#include <iostream>
#include <cassert>
using namespace std;

const double US_DOLLAR = 1.32;
const double POUND = 1.69;

class CurrencyAmountCDN {
    int dollars, cents;

    //HELPER FUNCTIONS
    void two_CDN_Amounts(int nDollars, int nCents) {
        int totalAmountsInCents = (dollars + nDollars) * 100 + (cents + nCents);
        double totalAmount = totalAmountsInCents / 100;

        dollars = totalAmountsInCents / 100;
        cents = totalAmountsInCents % 100;

        if (totalAmount <= 0) {
            dollars, cents = 0;
            nDollars, nCents = 0;
        }
    }

    void conversion(double conversionType){
        double totalAmount = (dollars * 100) + cents;
        totalAmount = totalAmount * conversionType / 100;

        dollars = totalAmount;
        cents = (totalAmount - dollars) * 100;
    };


public:
    //DEFAULT CONSTRUCTOR
    CurrencyAmountCDN() {
        dollars = 0;
        cents = 0;
    }

    //PARAMETRIC CONSTRUCTOR
    CurrencyAmountCDN(double amount) {
         if (amount <= 0) {
             dollars = 0;
             cents = 0;
         };
         dollars = amount; //able to do this because dollar is an int type
         cents = (amount - dollars) * 100;
    };

    //SERVICE FUNCTIONS
    void add(CurrencyAmountCDN positive){
        two_CDN_Amounts(positive.dollars, positive.cents);
    }

    void subtract(CurrencyAmountCDN subtract){
        two_CDN_Amounts(-subtract.dollars, -subtract.cents);
    }

    void currencySwap(double conversionType){
        conversion(conversionType);
    }

    void print() {
        cout << "---------------------" << endl;
        cout << "Dollars: ";
        cout << dollars << endl;
        cout << "Cents: ";
        cout << cents << endl;
        cout << "---------------------" << endl;
    }

};

void test_CurrencyAmountCDN() {
    CurrencyAmountCDN test1(11.11);
    CurrencyAmountCDN test2(34.56);
    CurrencyAmountCDN test3(324.561);

    test2.print();

    test2.add(test3);
    test2.print();

    test2.subtract(test1);
    test2.print();

    test1.currencySwap(POUND);
    test1.print();

    test3.currencySwap(US_DOLLAR);
    test3.print();
};


int main() {
    test_CurrencyAmountCDN();
}