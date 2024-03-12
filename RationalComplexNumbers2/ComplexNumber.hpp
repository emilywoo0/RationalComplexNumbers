//
//  ComplexNumber.hp
//  ComplexNumber
//
//  Created by Emily Woo on 9/27/23.
//

// -- pre-compiler guard to prevent circular includes
//    can also use #pragma once
#ifndef ComplexNumber_hpp
#define ComplexNumber_hpp

// -- some common standard include files
//    <> tells the pre-compiler to search the system directories
//    "" tells the pre-compiler to search the current directories
#pragma once
#include <string>
#include <cmath>
#include <iostream>
#include "RationalNumber.hpp"

// -- set the default namespace, avoids having to do std:: on objects/methods
using namespace std;

class ComplexNumber {
    
    // -- set up a public section
    //    can include member variables and functions
    //    can have multiple public sections, they do not have to be contiguous in the file
public:
    // -- default constructor
    ComplexNumber();
    // -- overload constructor
    ComplexNumber(double r, double i);
    // -- copy constructor
    ComplexNumber(ComplexNumber &rhs);
    // -- destructor
    ~ComplexNumber();
    
    void setReal(double r);
    void setImag(double r);
    
    double getReal();
    double getImag();
    
    ComplexNumber add(ComplexNumber rhs);
    ComplexNumber sub(ComplexNumber rhs);
    ComplexNumber div(ComplexNumber rhs);
    ComplexNumber mult(ComplexNumber rhs);
    
    double mag();
    ComplexNumber conj();
    ComplexNumber sqrt();
    
    bool equals(ComplexNumber o);
    
    ComplexNumber& operator=(const ComplexNumber& rhs);
    
    string toString();
    
    // -- set up a private section
    //    can include member variables and functions
    //    can have multiple private sections, they do not have to be contiguous in the file
private:
    // lhs = left hand sides
    
    const double PRECISION = 10000;
    
    RationalNumber real;
    RationalNumber imag;
    
    }; // -- don't forget the semi-colon
    
#endif
