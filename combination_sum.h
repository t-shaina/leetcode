#ifndef COMBINATION_SUM_H
#define COMBINATION_SUM_H
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> rez;
        if (candidates.size() == 1){
            if (candidates.at(0) == target) rez.push_back(vector<int>(candidates.at(0)));
            else return rez;
        }
        //sort(candidates.begin(), candidates.end());
        vector<int> current_digits;
        //current_digits.push_back(candidates.at(0));
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
    int sum(const vector<int>& buf){
        int sum = 0;
        for (auto i = buf.cbegin(); i < buf.cend(); i++)
            sum += *i;
        return sum;
    }
    void my_combinationSum(vector<int>& candidates, int new_target, int current_position, vector<int>& current_digits, vector<vector<int>>& rez){
        cout << "new target is: " << new_target << endl;
        cout << "currrent digits is: ";
        for (auto k = current_digits.begin(); k != current_digits.end(); k++)
            cout << *k;
        cout << endl;
        cout << "rez is: ";
        for (auto i = rez.begin(); i != rez.end(); ++i){
            for (auto j = i->begin(); j != i->end(); j++)
                std::cout << *j;
            std::cout << endl;
        }
        cout << endl;       
        int i = current_position;
        if (new_target < 2) {return;}
        if (i < candidates.size()){
            cout << "i is " <<candidates.at(i) << endl;
            /*if (candidates.at(i) > new_target) {
               current_digits.clear();
               continue;
            }*/
            if (new_target % candidates.at(i) == 0){
               rez.push_back(filling(current_digits, new_target / candidates.at(i), candidates.at(i)));
               //current_digits.clear();
               //continue;
            }
            //else {
                for (int  j = 0; j < (new_target / candidates.at(i)) + 1; j++){
                    int current_sum =  candidates.at(i) * j;
                    int second_term = new_target - current_sum;
                    cout << "current sum is " << current_sum << endl;
                    cout << "second_term is " << second_term << endl;
                    remove(current_digits, j -1);
                    inplace_filling(current_digits, j, candidates.at(i));
                    my_combinationSum(candidates, second_term, i + 1, current_digits, rez);
                }
            //}
                remove(current_digits, new_target / candidates.at(i));
        }
        //else return;
    }


};

#endif // COMBINATION_SUM_H
