#ifndef GENERATE_PARENTHESIS_H
#define GENERATE_PARENTHESIS_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rez;
        string str;
        str.resize(n * 2);
        generate(rez, str, 0, n, 0, 0);
        return rez;
    }
    static void generate(vector<string>& rez, string& str, int pos, int n, int open, int close){
        string str_ = str;
        str.resize(n * 2);
        if (close == n) { rez.push_back(str_); str.clear(); return;}
        else {

            if (open > close) {
                str.at(pos) = ')';
                generate(rez, str_,  pos + 1, n, open, close + 1);
            }
            if (open < n) {
                str.at(pos) = '(';
                generate(rez, str_,  pos + 1, n, open + 1, close);
            }
        }

    }
};

#endif // GENERATE_PARENTHESIS_H
