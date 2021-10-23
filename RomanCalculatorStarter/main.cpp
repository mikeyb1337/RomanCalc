#include <iostream>
#include <fstream>
#include "Token.hpp"
#include "InfixToPostfix.hpp"
#include "Tokenizer.hpp"
#include "RomanNumber.hpp"
#include <map>
#include <stack>

// Our Global Map for mapping our vars and values
std::map<char, RomanNumber> m;

//Basically the code from the lab lesson just adapted for romanNumbers and variables.

RomanNumber convertExpression(std::vector<Token*> &tokens) {
    std::stack<RomanNumber> numbers;
    for( auto token: tokens ) {
        if( token->isRomanNumber()   ) {
            RomanNumber romanNumber(token->romanNumber());
            numbers.push(romanNumber);
        }else if( token->isAVariable()   ){
            RomanNumber romanNumber(token->romanNumber());
            numbers.push(m[ token->variable() ]);
        }else {
            RomanNumber second = numbers.top(); numbers.pop();
            RomanNumber first = numbers.top(); numbers.pop();

            if( token->isAdditionOperator() )
                numbers.push(first + second);
            else if( token->isSubtractionOperator() )
                numbers.push(first - second);
            else if( token->isDivisionOperator() )
                numbers.push(first / second);
            else if( token->isModuloOperator() )
                numbers.push(first % second);
            else if( token->isMultiplicationOperator() )
                numbers.push(first * second);
            else {
                std::cout << "Expected an arithmetic operator instead found the following token.\n";
                token->print();
                exit(1);
            }
        }
    }
    return numbers.top();
}


void processAssignmentStatement(Token *token, Tokenizer &tokenizer) {
    Token *op = tokenizer.getToken();

    Token *exprToken = tokenizer.getToken();
    std::vector<Token *> expression;
     while( ! exprToken->eol() ) {
         expression.push_back(exprToken);
         exprToken = tokenizer.getToken();
     }
     expression.push_back(exprToken);

    // now, cnverst expression to postfix here.
    InfixToPostfix *itop = new InfixToPostfix();
    std::vector<Token *> postfixTokens;
    itop->convert( expression, postfixTokens );

    token->print();
    op->print();
    RomanNumber test(convertExpression(postfixTokens).getDecimalValue());
    //map with the variables a,b,c etc and the corresponding value.
    m.insert({ token->variable(), test.getRomanNumber() });
    std::cout << test.getRomanNumber()  << std::endl;

}



int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " nameOfAnInputFile\n";
        exit(1);
    }
    std::fstream inputStream;
    inputStream.open(argv[1], std::ios::in);
    if (!inputStream.is_open()) {
        std::cout << "Unable to open " << argv[1] << ". Terminating...";
        exit(1);
    }

    Tokenizer tokenizer(inputStream);
    Token *token = tokenizer.getToken();

    while( !token->eof() ) {
        processAssignmentStatement(token, tokenizer);
        token = tokenizer.getToken();
    }

    return 0;
}
