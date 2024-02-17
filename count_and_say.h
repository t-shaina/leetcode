#ifndef COUNT_AND_SAY_H
#define COUNT_AND_SAY_H
#include <string>
#include <iostream>
#include "stdlib.h"
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        return my_countAndsay(str, n, 1);
    }
    string my_countAndsay(string str, int n, int step){

        if (step == n) return str;
        else {
            string new_str;
            char current = str.at(0);
            int count = 0;
            for (int i = 0; i < str.size(); i++){
                if (str.at(i) != current){
                    new_str += to_string(count);
                    new_str += current;
                    current = str.at(i);
                    count = 1;
                }
                else count++;
                if (i == str.size() - 1){
                    new_str += to_string(count);
                    new_str += current;
                }

            }
            return my_countAndsay(new_str, n, ++step);
        }

    }
};
#endif // COUNT_AND_SAY_H
