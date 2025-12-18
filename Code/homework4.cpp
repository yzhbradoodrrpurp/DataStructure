//
// Created by 易治行 on 2025/11/6.
//

#include "LinkedString.h"
#include <string>
#include <iostream>

int main(void) {
    LinkedString* str = new LinkedString();
    std::string line;
    std::string pattern;

    std::cout << "Enter a line of string: ";
    std::cin >> line;

    str->getLine(line);

    std::cout << "Enter a pattern to search: ";
    std::cin >> pattern;

    LinkedString* patternStr = new LinkedString();
    patternStr->getLine(pattern);

    bool found = LinkedString::KMP(str, patternStr);

    if (found)
        std::cout << "Pattern found in the string." << std::endl;
    else
        std::cout << "Pattern not found in the string." << std::endl;


    delete str;

    return 0;
}