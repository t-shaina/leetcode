#ifndef NEXT_PERMUTATION_H
#define NEXT_PERMUTATION_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        bool is_max_order = true;
        for (auto i = nums.rbegin(); i != nums.rend() - 1; ++i){
            auto i_ = i;
            ++i_;
            if (*i > *i_){
                //if (i_ + 1 == nums.rend()) max_right = *i_ >= *max_right ?  i : max_right;
                auto rez = next(nums, *i_, nums.rbegin(), i_);
                my_swap(nums, rez, i_);
                sort(i_.base(), nums.end());
                is_max_order = false;
                break;
            }
        }
        if (is_max_order)  sort(nums.begin(), nums.end());

    }
    vector<int>::reverse_iterator next(vector<int>& nums, int compared, vector<int>::reverse_iterator first,  vector<int>::reverse_iterator last){
        vector<int>::reverse_iterator rez;
        for (auto i = first; i != last; ++i){
            if (*i > compared){
                rez = i;
                break;
            }
        }
        return rez;
    }
    void my_swap(vector<int>& nums, vector<int>::reverse_iterator first,  vector<int>::reverse_iterator second){
        int tmp = *first;
        *first = *second;
        *second = tmp;
    }

};
#endif // NEXT_PERMUTATION_H
