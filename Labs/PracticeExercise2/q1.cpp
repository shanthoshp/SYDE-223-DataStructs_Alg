#include <iostream>
#include <stdlib.h>
#include <string>
#include <cassert>
#include <random>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

//SHANTHOSH PUSHPARAJAH & TANJOT PANESAR


struct TwinPair {
  int val1, val2;
  TwinPair() : val1(0), val2(0) {}
};

 int find_divisor(unsigned int n,unsigned int d) {
   if (n<=1) {
     return n;
   } else if (n % d == 0) {
     return d;
   } else {
     return find_divisor(n, d-1);
  }
 }

bool is_prime(unsigned int n) {
  return (n > 1 && find_divisor(n, n/2) == 1);
};

TwinPair find_twin_primes(unsigned int chosen_index) {
  TwinPair print;
  int i = 0;
  int index = 0;

  if (chosen_index == 0) {
  } else {
    while (index != chosen_index) {
    i++;
    if (is_prime(i) && is_prime(i + 2)) {
        print.val1 = i;
        print.val2 = i + 2;
        index++;
      }       
    }
  } 
  return print;
}

int main() {
  TwinPair print;
  print = find_twin_primes(4);
  cout << print.val1 << " " << print.val2 << endl;
}
