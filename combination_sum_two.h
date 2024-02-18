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
            if (candidates.at(0) == target) rez.push_back(vector<int>{candidates.at(0)});
            else return rez;
        }
        else {
            sort(candidates.begin(), candidates.end());
            vector<int> current_digits;
            my_combinationSum(candidates, target, 0, current_digits, rez);
        }
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
        //if (new_target == 0){rez.push_back(current_digits); return;}
        if (new_target < 1) { return;}

        int i = current_position;
        int step = 1;
        int max_count_of_digit = 1;
        if (i < candidates.size()){
             cout << " i is : " << candidates.at(i) << endl;

            if (i < candidates.size() - 1){
                if (candidates.at(i) ==  candidates.at(i + 1)){
                    int count = count_of_digit(candidates, candidates.at(i));
                    step = count;
                    max_count_of_digit = count;
                    //auto iter =  std::remove(candidates.begin() + i + 1, candidates.end(), candidates.at(i));
                    //candidates.erase(iter, candidates.end());
                }
            }
            //if (new_target == candidates.at(i)){
                //rez.push_back(filling(current_digits, 1, candidates.at(i)));
            //}

            cout << "max count of digit  is: "<< max_count_of_digit << endl;
            for (int  j = 0; j < max_count_of_digit + 1; j++){
                cout << "j is: " << j << endl;

                int current_sum =  candidates.at(i) * j;
                int second_term = new_target - current_sum;
                remove(current_digits, j - 1);
                inplace_filling(current_digits, j, candidates.at(i));
                cout << "currrent digits is: ";
                for (auto k = current_digits.begin(); k != current_digits.end(); k++)
                    cout << *k;
                cout << endl;
                if (current_sum == new_target) {cout << "in if" << endl; rez.push_back(current_digits);}
                my_combinationSum(candidates, second_term, i + step, current_digits, rez);
            }
            remove(current_digits, max_count_of_digit);
        }

        else return;
    }

};
#endif // COMBINATION_SUM_TWO_H
