#ifndef SCANNERCLASS_H
#define SCANNERCLASS_H

#pragma once
#include <string>
#include "Token.h"
using namespace std;

// Function declaration for retrieving the next token from the input string based on the current position
Token getNextToken(const string& input, size_t& pos);

#endif
