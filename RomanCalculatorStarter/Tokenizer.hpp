//
// Created by Home on 10/11/21.
//

#ifndef ROMANCALCULATORSTARTER_TOKENIZER_HPP
#define ROMANCALCULATORSTARTER_TOKENIZER_HPP

#include <string>
#include <iostream>

#include "Token.hpp"

class Tokenizer {
public:
    Tokenizer(std::fstream &inStream);
    Token *getToken();

private:
    std::fstream &_inStream;
    bool isRomanNumber(char c);
    bool isVariable(char c);
    bool isArithmeticOperator(char c );
};


#endif //ROMANCALCULATORSTARTER_TOKENIZER_HPP
