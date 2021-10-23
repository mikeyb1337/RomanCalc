//
// Created by HOME on 10/19/2021.
//

#ifndef ROMANCALCULATORSTARTER_ROMANNUMBER_H
#define ROMANCALCULATORSTARTER_ROMANNUMBER_H
#include <vector>
#include <string>
#include "Token.hpp"
#include "InfixToPostfix.hpp"
#include "Tokenizer.hpp"

class RomanNumber {

public:

    void print(){
        std::cout << _decimalValue << std::endl;
        std::cout << _romanNumber << std::endl;
    }

    RomanNumber() {}
    RomanNumber(int n){ _decimalValue = n; _romanNumber = decimalToRoman( n ); }
    RomanNumber( std::string s){ _romanNumber = s; _decimalValue = romanToDecimal( s ); }


    RomanNumber operator+ (const RomanNumber& c) const
    {
        RomanNumber result;
        result._decimalValue = this->_decimalValue + c._decimalValue;
        return result;
    }

    void operator= (const int c) {
        this->setDecimalValue( c );
    }

    RomanNumber operator- (const RomanNumber& c) const
    {
        RomanNumber result;
        result._decimalValue = this->_decimalValue - c._decimalValue;
        return result;
    }

    RomanNumber operator* (const RomanNumber& c) const
    {
        RomanNumber result;
        result._decimalValue = this->_decimalValue * c._decimalValue;
        return result;
    }

    RomanNumber operator/ (const RomanNumber& c) const
    {
        RomanNumber result;
        result._decimalValue = this->_decimalValue / c._decimalValue;
        return result;
    }

    RomanNumber operator% (const RomanNumber& c) const
    {
        RomanNumber result;
        result._decimalValue = this->_decimalValue % c._decimalValue;
        return result;
    }

    int romanToDecimal( std::string );
    std::string decimalToRoman( int n );

    void setRomanNumber( std::string s );
    void setDecimalValue( int n );

    int getDecimalValue() { return _decimalValue;}
    std::string getRomanNumber() { return _romanNumber;}

private:

    bool isAValidRomanNumber( std::string _romanNumber );
    std::string _romanNumber;
    int _decimalValue;




};


#endif //ROMANCALCULATORSTARTER_ROMANNUMBER_H
