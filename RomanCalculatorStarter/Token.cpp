//
// Created by Home on 10/11/21.
//

#include <iostream>
#include "Token.hpp"

bool Token::isArithmeticOperator(char c ) {
    return c == '+' || c == '/' || c == '*' || c == '-' || c == '%' || c == ')' || c == '(' || c == '=';
}

bool Token::isVariable(char c ) {
    return c >= 'a' && c <= 'z';
}


void Token::print() {
    if( eol() ) std::cout << "" ;
    else if( eof()                      )  std::cout << "EOF" ;
    else if( isOpenParen()              )  std::cout << "(" ;
    else if( isCloseParen()            )  std::cout << ")" ;
    else if( isEqualSign()              )  std::cout << " equals " ;
    else if( isMultiplicationOperator() )  std::cout << " * " ;
    else if( isAdditionOperator()       )  std::cout << " + " ;
    else if( isSubtractionOperator()    )  std::cout << " - " ;
    else if( isModuloOperator()         )  std::cout << " % " ;
    else if( isDivisionOperator()       )  std::cout << " % " ;
    else if( isRomanNumber()            )  std::cout << " " << romanNumber() << " ";
    else if( isAVariable()              )  std::cout << " " << variable() << " ";
    else {
        std::cout << "Token::print -- Came across an unknown token. Terminating...\n";
        exit(1);
    }
}

void Token::init() {
    _romanNumber = "";
    _eof = _eol = false;
    _symbol = '\0';
}

bool Token::isRomanNumber() const { return _romanNumber.length() > 0; }
