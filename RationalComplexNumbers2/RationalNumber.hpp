//
//  RationalNumber.hpp
//  RationalNumber
//
//  Created by Emily Woo on 10/17/23.
//

#ifndef RationalNumber_hpp
#define RationalNumber_hpp

#include <stdio.h>
#pragma once
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class RationalNumber {
    
public:
    
    // -- default constructor
    RationalNumber();
    
    // -- overload constructor
    RationalNumber(int n, int d);
//    RationalNumber(int n, int d);
    
    // -- copy constructor
    RationalNumber(RationalNumber &rhs);
    
    // -- destructor
    ~RationalNumber();
    
    // -- setters
    void setNumerator(long long n) ;
    void setDenominator(long long d) ;
//    void setNumerator(int n);
//    void setDenominator(int d);
    
    // -- getters
    long long getNumerator() const;
    long long getDenominator() const;
    
    // -- equals
    bool equals(RationalNumber o);
    
    // -- string
    string toString();
    
    // -- rational number functions
    RationalNumber add(RationalNumber rhs);
    RationalNumber sub(RationalNumber rhs);
    RationalNumber mult(RationalNumber rhs);
    RationalNumber div(RationalNumber rhs);
    
    double sqrt();
    
protected:
    
    // -- change to long long
    long long num;
    long long den;
};


#endif /* RationalNumber_hpp */

