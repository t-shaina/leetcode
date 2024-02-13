#ifndef LETTER_COMBINATIONS_OF_A_STRING_NUMBER_H
#define LETTER_COMBINATIONS_OF_A_STRING_NUMBER_H
#include <vector>
#include <iostream>

using namespace std;
class Phone_digit{
    int alphabet_begin = (int){'a'};
    int size = 0;
public:
    string* letters;
    Phone_digit( int digit){
        //if (digit > 9) return;
        letters = new string();

        if (digit < 7){
            int letters_begin = alphabet_begin + 3 * (digit - 2);
            size = 3;
            for (int i = 0; i < size; i++) {letters->push_back((char)letters_begin++);}
        }
        if (digit == 7){
             size = 4;
            int letters_begin = alphabet_begin + 3 * (digit - 2);
            for (int i = 0; i < size; i++) letters->push_back((char)letters_begin++);
        }
        if (digit == 9){
             size = 4;
            int letters_begin = alphabet_begin + 3 * (digit - 2) + 1;
            for (int i = 0; i < size; i++) letters->push_back((char)letters_begin++);
        }
        if (digit == 8){
             size = 3;
            int letters_begin = alphabet_begin + 3 * (digit - 2) + 1;
            for (int i = 0; i < size; i++) letters->push_back((char)letters_begin++);
        }

    }
    static vector<string> combinations(const Phone_digit&& first){
        vector<string> rez;
        for (auto i = first.letters->begin(); i != first.letters->end(); ++i){
            rez.push_back({*i});
        }
        return rez;
    }
    static void combinations(string& first, const vector<Phone_digit>& phone_letters, vector<Phone_digit>::iterator position, vector<string>& rez){

        if (position == phone_letters.end()){
            rez.push_back(first);
        }
        else{
            bool is_move_to_next = 0;
            vector<Phone_digit>::iterator inner_position = position;
            for (auto j = position->letters->begin(); j != position->letters->end(); j++){

                string combi = first;
                combi += {*j};
                combinations (combi, phone_letters, ++position, rez);
                --position;
            }
        }
    }

    //~Phone_digit(){ delete letters;}
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> rez;
        if (digits.empty()) return rez;
        if (digits.size() == 1) return Phone_digit::combinations(digits.front() - '0');
        auto  end = digits.end();
        vector<Phone_digit> phone_letters;
        for (auto i = digits.begin(); i != end; i++){
                phone_letters.push_back(*i - '0');
        }
        auto position = ++phone_letters.begin();
        string first = *phone_letters.begin()->letters;
        //vector<string> combi;
        for (auto i = first.begin(); i != first.end(); ++i){
                string element_of_first = string{*i};
                Phone_digit::combinations(element_of_first, phone_letters, position, rez);
        }
        return rez;
    }
};

#endif // LETTER_COMBINATIONS_OF_A_STRING_NUMBER_H
