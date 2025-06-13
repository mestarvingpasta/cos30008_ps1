#include "Combination.h"
#include <iostream>
using namespace std;

Combination::Combination(size_t aN, size_t aK) {
    fN = aN;
    fK = aK;
}

size_t Combination::getN() const {
    return fN;
}

size_t Combination::getK() const {
    return fK;
}

unsigned long long Combination::operator()() const{
    //the consition tho
    if (fK > fN) {
        return 0;
    }

    if (fK == 0 || fK == fN){
        return 1;
    }

    unsigned long long result =1;
    size_t k = fK;
    for (size_t i = 1; i <= k; ++i){
        result = result * (fN - (i - 1)) / i;
    }

    return result;
}

