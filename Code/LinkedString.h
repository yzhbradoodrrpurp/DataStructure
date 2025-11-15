//
// Created by 易治行 on 2025/11/6.
//

#ifndef LINKEDSTRING_H
#define LINKEDSTRING_H

#include "LinkedList.h"
#include <string>

class LinkedString: public LinkedList<char> {
public:
    LinkedString(): LinkedList<char>(){}
    ~LinkedString() override = default;

    void getLine(std::string str) {
        for (auto ch: str)
            this->append(new Node<char>(ch));
    }

    static bool KMP(LinkedString* source, LinkedString* pattern) {
        std::vector<int> lps = pattern->LPS();

        int i = 0, j = 0;

        while (i < source->length && j < pattern->length) {
            if ((*source)[i]->getValue() != (*pattern)[j]->getValue()) {
                if (j!= 0)
                    j = lps[j - 1];
                else
                    i += 1;
            }
            else {
                i += 1;
                j += 1;
            }

        }

        if (j == pattern->length)
            return true;

        return false;
    }


    std::vector<int> LPS() {
        std::vector<int> lps;

        for (int i = 0; i < this->length; i++)
            lps.push_back(0);

        int i = 1, j = 0;

        while (i < this->length) {
            if ((*this)[i]->getValue() == (*this)[j]->getValue()) {
                j += 1;
                lps[i] = j;
                i += 1;
            }
            else {
                if (j != 0)
                    j = lps[j - 1];
                else {
                    lps[i] = 0;
                    i += 1;
                }
            }
        }

        return lps;
    }
};

#endif //LINKEDSTRING_H
