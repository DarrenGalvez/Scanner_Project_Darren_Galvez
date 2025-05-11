#include <iostream>
#include <vector>
#include "ScannerClass.h"
#include "Token.h"
#include "ScannerClass.cpp"
using namespace std; 

int main() {
    //Requests user input for arithmetic expression
    string input;
    cout << "Enter an arithmetic expression: "; 
    getline(cin, input); 

    size_t position = 0;
    vector<Token> tokens; 

    //getNextToken is called repeatedly to tokenize the entire user input
    while (true) {
       Token token = getNextToken(input, position);
       if (token.type == END_OF_INPUT) {
        break;
       }
       tokens.push_back(token); 
    }
    //Each token's type and value is printed
    cout << "\nTokens:\n";
    for (const Token& token : tokens) {
        cout << "Token(Type: ";
        switch (token.type) {
            case NUMBER: cout << "NUMBER"; break;
            case OPERATOR: cout << "OPERATOR"; break;
            case PARENTHESIS: cout << "PARENTHESIS"; break;
            case UNKNOWN: cout << "UNKNOWN"; break;
            default: cout << "OTHER"; break;
        }
        cout << ", Value: \"" << token.value << "\")\n";
    }

    return 0;
}