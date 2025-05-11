#ifndef TOKEN_H
#define TOKEN_H

#include <string>
using namespace std;

// All user inputs are to be defined by TokenType
enum TokenType {
    NUMBER,   //Numeric Value
    OPERATOR, //+,-,*,/
    PARENTHESIS,// Open and Close parenthesis
    UNKNOWN,  // Data that doesn't fit in the other categories
    END_OF_INPUT //Terminate scan token
};

//The struct holds both type and value of the token
struct Token {
    TokenType type;
    string value;

    //Constructor 
    Token(TokenType typeOfToken, const string& valueOfToken);
};

#endif