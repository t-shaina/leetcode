#ifndef COMBINATION_SUM_TWO_H
#define COMBINATION_SUM_TWO_H
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> rez;
        if (candidates.size() == 1){
            if (candidates.at(0) == target) rez.push_back(vector<int>(candidates.at(0)));
            else return rez;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> current_digits;
        my_combinationSum(candidates, target, 0, current_digits, rez);
        return rez;
    }
    vector<int> filling(vector<int> buf, int count, int digit){
        for (int i = 0; i < count; i++)
            buf.push_back(digit);
        return buf;
    }
    void inplace_filling(vector<int>& buf, int count, int digit){
        for (int i = 0; i < count; i++)
            buf.push_back(digit);
    }
    void remove(vector<int>& buf, int count){
        for (int i = 0; i < count; i++)
            buf.pop_back();
    }
    int count_of_digit(vector<int>& buf, int digit){
        int count = 0;
        for (int i = 0; i < buf.size(); i++){
            if (buf.at(i) == digit) count++;
        }
        return count;
    }
    void my_combinationSum(vector<int>& candidates, int new_target, int current_position, vector<int>& current_digits, vector<vector<int>>& rez){
        if (new_target < 1) {return;}
        int i = current_position;

        int max_count_of_digit = 2;
        if (i < candidates.size()){
             //cout << " i is : " << candidates.at(i) << endl;
            if (i > 0 ){
                if (candidates.at(i) ==  candidates.at(i - 1)){
                    int count = count_of_digit(candidates, candidates.at(i));
                    if (current_digits.empty()) { max_count_of_digit = 1;}
                    else if (count_of_digit(current_digits, candidates.at(i)) <= count - 1 && current_digits.back() != candidates.at(i)) { max_count_of_digit = 1;}
                }
            }
            if (new_target == candidates.at(i)){
                rez.push_back(filling(current_digits, 1, candidates.at(i)));
            }
            for (int  j = 0; j < max_count_of_digit; j++){
                int current_sum =  candidates.at(i) * j;
                int second_term = new_target - current_sum;
                inplace_filling(current_digits, j, candidates.at(i));
                my_combinationSum(candidates, second_term, i + 1, current_digits, rez);
            }
            remove(current_digits, max_count_of_digit - 1);
        }

        else return;
    }

};
#endif // COMBINATION_SUM_TWO_H
