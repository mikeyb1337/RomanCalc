//
// Created by Home on 10/11/21.
//

#include "Tokenizer.hpp"
#include <fstream>
#include <iostream>



Tokenizer::Tokenizer(std::fstream &inStream): _inStream{inStream} {}

bool Tokenizer::isArithmeticOperator(char c ) {
    return c == '+' || c == '/' || c == '*' || c == '-' || c == '%' || c == ')' || c == '(' || c == '=';
}

bool Tokenizer::isVariable(char c) {
    return c >= 'a' && c <= 'z';
}

bool Tokenizer::isRomanNumber(char c) {
    return c == 'I' || c == 'V' || c == 'X' || c == 'L' || c == 'C' || c == 'D' || c == 'M';
}



Token *Tokenizer::getToken() {

    char c;
    while (_inStream.get(c) && c != '\n' && isspace(c)); // discard c, it is a white space character, but not eol

    Token *token = new Token();
    if (_inStream.eof())
        token->eof() = true;
    else if (c == '\n')
        token->eol() = true;
    else if (isVariable(c)) {
//        std::cout << "Encountered a Variable character ->" << c <<
//                  "<- in getToken. " << std::endl;
        token->setSymbol(c);

    } else if (isArithmeticOperator(c)  ) {
 //       std::cout << "Encountered an Arithmetic Operator ->" << c <<
   //               "<- in getToken. " << std::endl;
        token->arithmeticOperator() = c;

    }
    else if ( isRomanNumber( c ) ) {
        // _inStream.putback(c);
        std::string romanNumber;
        romanNumber += c;
        while(isRomanNumber(_inStream.peek())) {
            _inStream.get(c);
            romanNumber += c;
        }
  //      std::cout << "Encountered a Roman Number ->" << romanNumber <<
   //               "<- in getToken. " << std::endl;
        token->romanNumber(romanNumber);
    }
    else
    {
     //   std::cout << "Encountered an unknown character ->" << c <<
    //              "<- in getToken. Terminating... ";
        exit(1);
    }

    return token;
}