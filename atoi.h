#ifndef ATOI_H
#define ATOI_H

#include <regex>
#include <string>
#include <iostream>
#include <utility>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int64_t rez = 0;
        bool positive = 1;
        auto ptr = s.begin();
        while (*ptr == ' ') ptr++;
        //bool check_positive = ;
        if (*ptr == '+') {ptr++;}
        else if (*ptr == '-') { positive = 0; ptr++;}
        while (*ptr >= '0' && *ptr <= '9'){
            rez = rez * 10 + *ptr - '0';
            cout << "rez  is " << rez << endl;
            if (positive && rez >= INT_MAX) return INT_MAX;
            if (!positive && rez > INT_MAX) return INT_MIN;
            ++ptr;
        }
        return positive ? rez : -rez;
    }
};


#endif // ATOI_H
