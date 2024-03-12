//
//  ComplexNumber.cpp
//  ComplexNumber
//
//  Created by Emily Woo on 9/27/23.
//

#include "ComplexNumber.hpp"
#include "RationalNumber.hpp"
#include <cmath>
#include <string>

using namespace std;

    // constructors
    ComplexNumber::ComplexNumber() {
        }

    // -- 5 digit PRECISION
    ComplexNumber::ComplexNumber(double r, double i) {
        this->real = RationalNumber((r * PRECISION), PRECISION);
        this->imag = RationalNumber((i * PRECISION), PRECISION);
//        this->real = RationalNumber((int)(r * PRECISION), PRECISION);
//        this->imag = RationalNumber((int)(i * PRECISION), PRECISION);

        }

    ComplexNumber::ComplexNumber(ComplexNumber &rhs) { // rhs = right hand side
        this->real = RationalNumber((rhs.getReal() * PRECISION), PRECISION);
        this->imag = RationalNumber((rhs.getImag() * PRECISION), PRECISION);
//        this->real = RationalNumber((int)(rhs.getReal() * PRECISION), PRECISION);
//        this->imag = RationalNumber((int)(rhs.getImag() * PRECISION), PRECISION);
        }
    
    // destructor
    ComplexNumber::~ComplexNumber() {
        }

    // setters
    // -- converts double to a rational number
    void ComplexNumber::setReal(double r) {
        this->real = RationalNumber((r * PRECISION), PRECISION);
//        this->real = RationalNumber((int)(r * PRECISION), PRECISION);
    }

    void ComplexNumber::setImag(double i) {
        this->imag = RationalNumber((i * PRECISION), PRECISION);
//        this->imag = RationalNumber((int)(i * PRECISION), PRECISION);
    }

    // -- getters
    // -- converts rational number to a double and returns
    double ComplexNumber::getReal() {
        double r = ((double)this->real.getNumerator() / (double)this->real.getDenominator());
        return r;
    }

    double ComplexNumber::getImag() {
        double i =((double)this->imag.getNumerator() / (double)this->imag.getDenominator());
        return i;
    }

    string ComplexNumber::toString() {
        
       string msg;
        
            
        // if imaginary part is greater than or equal to 0 print
        if (getImag() >= 0) {
            
            msg = to_string(getReal()) + " + " + to_string(getImag()) + "i";
            
            return msg;
        }
        else if (getImag() < 0) {
            setReal(getReal());
            setImag(getImag() * -1);
            
            msg = to_string(getReal()) + " - " + to_string(getImag()) + "i";
        
            return msg;
        }
            
        return msg;
    }
     
    // -- Add two complex rational numbers
    ComplexNumber ComplexNumber::add(ComplexNumber rhs) {
        
        ComplexNumber sum;
        // -- add the real Rational Numbers of each complex number (real part)
        sum.setReal(this->getReal() + rhs.getReal());
        
        // -- add the complex Rational Numbers of each complex number (complex part)
        sum.setImag(this->getImag() + rhs.getImag());
    
        
        return sum;
    }

    ComplexNumber ComplexNumber::sub(ComplexNumber rhs) {
        
        ComplexNumber diff;
        
        // -- subtract the real parts of each complex number (real part)
        diff.setReal(this->getReal() - rhs.getReal());
        // -- subtract the complex parts of each complex number (complex part)
        diff.setImag(this->getImag() - rhs.getImag());
        
        return diff;
    }

    ComplexNumber ComplexNumber::mult(ComplexNumber rhs) {
        
        // -- formula: (a + ib) (c + id) = (ac = bd) + i(ad +bc)
                // -- i = imaginary parts
                // -- source: https://www.cuemath.com/numbers/multiplying-complex-numbers/

        ComplexNumber prod;
        
        // -- calculate the real part
        // -- (ac = bd)
        prod.setReal( (this->getReal() * rhs.getReal()) - (this->getImag() * rhs.getImag()) );
        // -- calculate the imaginary part
        // -- i(ad +bc)
        prod.setImag( (this->getReal() * rhs.getImag()) + (this->getImag() * rhs.getReal()) );
        
        return prod;
        
    }


    ComplexNumber ComplexNumber::div(ComplexNumber rhs) {
        
        // -- formula source: https://www.cuemath.com/numbers/division-of-complex-numbers/
        ComplexNumber quo;
    
        if ( (abs(rhs.getReal()) < 0.000001) || (abs(rhs.getImag()) < 0.000001) ) {
            throw ("divide by 0");
            
        }
        else {
            
            // -- calculate the real part
            quo.setReal(( (this->getReal() * rhs.getReal()) + (this->getImag() * rhs.getImag()) ) / ( (pow(rhs.getReal(), 2)) + (pow(rhs.getImag(), 2)) ));
            // -- calculate the imaginary part
            quo.setImag(( (this->getImag() * rhs.getReal()) - (this->getReal()  * rhs.getImag()) ) / ( (pow(rhs.getReal(), 2)) + (pow(rhs.getImag(), 2)) ));
                
            return quo;
        }
            
            
    }
        

    double ComplexNumber::mag() {
        
        // -- formula square root of (a^2 + b^2)
        // -- source: https://www.cuemath.com/algebra/modulus-of-complex-number/
        return std::sqrt(pow(this->getReal(), 2)+ pow(this->getImag(), 2));
        
    }

    ComplexNumber ComplexNumber::conj() {
        // -- the conjugate is a complex number with the the sign of the imaginary part of the original number reversed
        // -- source: https://www.mathcentre.ac.uk/resources/sigma%20complex%20number%20leaflets/sigma-complex6-2009-1.pdf
        ComplexNumber conj;
        
        conj.setReal(this->getReal());
        conj.setImag((this->getImag() * -1));
        
        return conj;
    }

// currently acts like an int
    ComplexNumber ComplexNumber::sqrt() {
        
        // -- formula source: https://www.cuemath.com/algebra/square-root-of-complex-number/
        ComplexNumber sq;
        
        if ( (this->getImag() - 0) < 0.000001 ) {
            if (this->getReal() >= 0) {
                sq.setReal(std::sqrt(this->getReal()) );
            }
            else if (getReal() - 0 < 0.000001) {
                sq.setReal(std::sqrt(this->getReal() * -1));
            }
        }
        if ((this->getImag() - 0 < 0.000001) || (this->getImag() - 0 > 0.000001)) {
            sq.setReal(std::sqrt( (this->getReal() + (std::sqrt(pow(getReal(), 2) + pow(getImag(), 2)))) / 2 ));
            sq.setImag(std::sqrt( ((this->getReal() * -1) + (std::sqrt(pow(getReal(), 2) + pow(getImag(), 2)))) / 2 ));
        }
        
        return sq;
    }

    bool ComplexNumber::equals(ComplexNumber o) {
            
        if ( (abs(this->getReal() - o.getReal()) < 0.000001) && (abs(this->getImag() - o.getImag()) < 0.000001))  {
                return true;
        }
    
        
        return false;
    }

    ComplexNumber& ComplexNumber::operator= (const ComplexNumber& rhs) {
        this->real.setNumerator(rhs.real.getNumerator());
        this->real.setDenominator(rhs.real.getDenominator());
        
        this->imag.setNumerator(rhs.imag.getNumerator());
        this->imag.setDenominator(rhs.imag.getDenominator());
        
        return * this;
    }

