#ifndef MULTIPLY_STRINGS_H
#define MULTIPLY_STRINGS_H
#include <iostream>
using namespace std;

class Solution {
public:
    string reverse (string str){
        std::cout << "str in reverse is "<< str <<  std::endl;
        string rez("");
        for (int i = str.length() - 1; i > -1; --i){
            rez.push_back(str.at(i));
        }
        std::cout << "rez in reverse is "<< rez <<  std::endl;
        return rez;
    }
    string inner_multiply (string first, char second, int decade){
        std::cout << "first second  in inner multiply is "<< first << " " << second <<  std::endl;
        string reverse_rez("");
        int transfer = 0;
        for (int i = first.length() - 1; i > -1; --i) {
            int buf = (first.at(i) - '0') * (second - '0') + transfer;
            if (buf > 9){
                transfer = buf / 10;
            }
            else transfer = 0;
            reverse_rez += to_string(buf % 10);
        }
        if (transfer)reverse_rez += to_string(transfer);
        string rez = reverse(reverse_rez);
        for (int j = 0; j < decade; j++)
            rez+= '0';
        std::cout << "rez in inner multiply is "<< rez<<  std::endl;
        return rez;
    }
    string inner_sum (string first, string second){
        std::cout << "first second  in inner sum is "<< first << " " << second <<  std::endl;
        string reverse_rez("");
        int transfer = 0;
        int first_i = first.length() - 1;
        int second_i = second.length() - 1;
        while (first_i > -1 || second_i > -1) {
            int left_term = 0;
            int right_term = 0;
            if (first_i > -1) left_term = first.at(first_i) - '0';
            if (second_i > -1) right_term = second.at(second_i) - '0';
            int buf =  left_term + right_term + transfer;
            if (buf > 9){
                transfer = buf / 10;
            }
            else transfer = 0;
            reverse_rez += to_string(buf % 10);
            first_i --;
            second_i--;
        }
        if (transfer) reverse_rez += to_string(transfer);
        string rez = reverse(reverse_rez);
        std::cout << "rez in inner sum is "<< rez<<  std::endl;
        return rez;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string rez("");
        for (int i = 0; i < num2.length(); i++){
            rez = inner_sum(rez, inner_multiply(num1, num2.at(i), num2.length() - i - 1));
        }
        std::cout << "rez in multiply is "<< rez<<  std::endl;
        return rez;
    }
};

#endif // MULTIPLY_STRINGS_H
