//
// Created by HOME on 10/19/2021.
//

#include "RomanNumber.hpp"
#include <vector>
#include <string>
#include "Token.hpp"
#include "InfixToPostfix.hpp"
#include "Tokenizer.hpp"
#include<map>
#include <array>

//given a decimal number, converts it to the Roman Number that corresponds to it.
std::string RomanNumber::decimalToRoman(int num) {
    int decimal[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char *symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int i = 0;
    std::string s;
    while(num) {
        while(num/decimal[i]) {
            s = s + symbol[i];
            num -= decimal[i];
        }
        i++;
    }    return s;

}
//given a Roman Number, converts it to its corresponding decimal number and returns it
int RomanNumber::romanToDecimal(std::string str) {
    std::map<char, int> m;
    m.insert({ 'I', 1 });
    m.insert({ 'V', 5 });
    m.insert({ 'X', 10 });
    m.insert({ 'L', 50 });
    m.insert({ 'C', 100 });
    m.insert({ 'D', 500 });
    m.insert({ 'M', 1000 });
    int sum = 0;
    for (int i = 0; i < str.length(); i++) {
        if (m[str[i]] < m[str[i + 1]]) {
            sum+=m[str[i+1]]-m[str[i]];
            i++;
            continue;
        }
        sum += m[str[i]];
    }
    return sum;
}


bool RomanNumber::isAValidRomanNumber(std::string romanNumber) {
   return romanNumber == decimalToRoman( romanToDecimal( romanNumber ) );
}

void RomanNumber::setRomanNumber(std::string s) {
    _romanNumber = s;
    _decimalValue = romanToDecimal( _romanNumber );

}

void RomanNumber::setDecimalValue(int n) {
    _decimalValue = n;
    _romanNumber = decimalToRoman( n );
}

