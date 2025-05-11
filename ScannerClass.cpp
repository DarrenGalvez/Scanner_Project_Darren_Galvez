#include "ScannerClass.h"
#include <cctype>
using namespace std;

// Token constructor implementation
Token::Token(TokenType typeOfToken, const string& valueOfToken)
    : type(typeOfToken), value(valueOfToken) {}

// Scans the input string and returns the next token
Token getNextToken(const string& input, size_t& pos) {
    // Skip any leading whitespace
    while (pos < input.length() && isspace(input[pos])) {
        ++pos;
    }

    // End of input check
    if (pos >= input.length()) {
        return Token(END_OF_INPUT, "");
    }

    char currChar = input[pos];

    // Handle negative numbers
    if (currChar == '-' && pos + 1 < input.length() && isdigit(input[pos + 1])) {
        string number(1, input[pos++]); // Start with the '-' sign

        while (pos < input.length() && isdigit(input[pos])) {
            number += input[pos++];
        }

        return Token(NUMBER, number);
    }

    // Handle positive numbers
    if (isdigit(currChar)) {
        string number;

        while (pos < input.length() && isdigit(input[pos])) {
            number += input[pos++];
        }

        return Token(NUMBER, number);
    }

    // Handle arithmetic operators
    if (currChar == '+' || currChar == '-' || currChar == '*' || currChar == '/' || currChar == '%') {
        ++pos;
        return Token(OPERATOR, string(1, currChar));
    }

    // Handle parentheses
    if (currChar == '(' || currChar == ')') {
        ++pos;
        return Token(PARENTHESIS, string(1, currChar));
    }

    // Unknown character
    string unknownChar(1, input[pos++]);
    return Token(UNKNOWN, unknownChar);
}
