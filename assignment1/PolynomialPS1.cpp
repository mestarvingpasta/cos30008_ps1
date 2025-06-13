#include <cmath>
#include "Polynomial.h"
#include <iostream>
using namespace std;

double Polynomial::operator()(double aX) const {
    double result = 0.0;

    for (size_t i = 0; i <= fDegree; i++) {
        result += fCoeffs[i] * pow(aX, i);
    }

    return result;
}

Polynomial Polynomial::getDerivative() const {
    Polynomial derivative;
    if (fDegree == 0) {
        return derivative;
    }

    derivative.fDegree = fDegree - 1;
    for (size_t i = 1; i <= fDegree; i++) {
        derivative.fCoeffs[i -1] = fCoeffs[i] * i;
    }

    return derivative;
}

Polynomial Polynomial::getIndefiniteIntegral() const {
    Polynomial integral;

    integral.fDegree = fDegree + 1;
    integral.fCoeffs[0] = 0.0;

    for (size_t i=0; i <= fDegree; i++) {
        integral.fCoeffs[i + 1] = fCoeffs[i] / (i + 1);
    }

    return integral;
}

double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const{
    Polynomial integral = getIndefiniteIntegral();
    return integral(aXHigh) - integral(aXLow);
}

