#include "BernsteinBasisPolynomial.h"
#include <cmath>
#include <iostream>
using namespace std;

BernsteinBasisPolynomial::BernsteinBasisPolynomial(unsigned int aV, unsigned int aN) : fFactor(aN, aV) {
}

double BernsteinBasisPolynomial::operator()(double aX) const {
    unsigned int v = fFactor.getK();
    unsigned int n = fFactor.getN();

    //unsigned is integer > 0 

    double result = static_cast<double>(fFactor());

    result *= pow(aX, v);
    result *= pow(1.0 -aX, n-v);

    return result;
}