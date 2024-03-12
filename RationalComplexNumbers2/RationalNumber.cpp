//
//  RationalNumber.cpp
//  RationalNumber
//
//  Created by Emily Woo on 10/17/23.
//

#include "RationalNumber.hpp"
#include "ComplexNumber.hpp"
#include <string>
#include <cmath>


using namespace std;

// -- constructors
RationalNumber::RationalNumber() {
}

RationalNumber::RationalNumber(int n, int d) {
    this->num = n;
    this->den = d;
}

RationalNumber::RationalNumber(RationalNumber &rhs) {
    this->num = rhs.num;
    this->den = rhs.den;
}

// -- destructor
RationalNumber::~RationalNumber() {
}

// -- setters
void RationalNumber::setNumerator(long long n) {
    this->num = n;
}

void RationalNumber::setDenominator(long long d) {
    this->den = d;
}

// -- getters
long long RationalNumber::getNumerator() const {
    return this->num;
}

long long RationalNumber::getDenominator() const {
    return this->den;
}


bool RationalNumber::equals(RationalNumber rn) {
    
    if ( (abs(this->num - rn.num) < 0.000001) && (abs(this->den - rn.den) < 0.000001))  {
        return true;
    }
    
    return false;
}

// -- toString
string RationalNumber::toString() {
    
    string msg;
    long long n = this->num;
    long long d = this->den;
    
    // -- if "this" is a whole number return as a whole number
    if ( (n != 0) && ((n % d) == 0)) {
        msg = n / d;
        return msg;
    }
    
    // -- find GFC to simplify fractions
    for (int i = 10; i > 1; i--) {
        // -- tests if numerator and denominator are both divisible by value i
        if ((n % i == 0) && (d % i == 0)) {
            n = this->num / i;
            d = this->den / i;
        }
    }
    
    // -- negative numerator if necessary (denominator should not be negative)
    // -- cancel double negative if necessary
    if (d < 0) {
        n = n * -1;
        d = abs(d);
    }
    
    // -- simplify to mixed number
    if ( n > d ) {
        int whole = floor(n / d);
        n = n - (whole * d);
        
        msg = to_string(whole) + " " + to_string(n) + "/" + to_string(d);
        return msg;
    }
    
    msg = to_string(n) + "/" + to_string(d);
    
    return msg;
    
}

// -- Adds two Rational Numbers
RationalNumber RationalNumber::add(RationalNumber rhs) {
   
    RationalNumber sum;
            
    if (this->den == rhs.den) {
        sum.num = this->num + rhs.num;
        sum.den = this->den;
    }
    else {
        sum.num = (this->num * rhs.den) + (rhs.num * this->den);
        sum.den = this->den * rhs.den;
    }
    
    return sum;
    
}

// -- Subtracts two Rational Numbers
RationalNumber RationalNumber::sub(RationalNumber rhs) {
    RationalNumber diff;
    
    if (this->den == rhs.den) {
        
        diff.num = this->num - rhs.num;
        diff.den = this->den;
        
    }
    else {
        diff.num = (this->num * rhs.den) - (rhs.num * this->den);
        diff.den = this->den * rhs.den;
    }
    
    return diff;

}

// -- Multiplies two Rational Numbers
RationalNumber RationalNumber::mult(RationalNumber rhs) {
    
    RationalNumber prod;
    
    prod.num = this->num * rhs.num;
    prod.den = this->den * rhs.den;
    
    return prod;
    
}

// -- STILL NEEDS  THROW ARITHMETIC EXCEPTION IF DEN IS 0
RationalNumber RationalNumber::div(RationalNumber rhs) {
    
    RationalNumber quo;

    if ( (rhs.num == 0) || (rhs.den == 0) ) {
        throw ("divide by 0");
    }
        quo.num = this->num * rhs.den;
        quo.den = this->den * rhs.num;
    
    return quo;
    
}

// -- Finds square root of a Rational Number
double RationalNumber::sqrt() {
    
    double sqrt = std::sqrt((double)this->num / (double)this->den);
    
    return sqrt;
    
}


