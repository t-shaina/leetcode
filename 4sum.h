#ifndef SUM_H
#define SUM_H

#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> rez;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size - 3; i++){
            //cout << "nums at i is" << nums.at(i) << endl;
            int i_ = i;
            if (i > 0 && nums.at(i) == nums.at(--i_)) { /*++i_;*/ continue;}
            for (int x = i + 1; x < size - 2; ++x){
                int x_ = x;
                if (x > i + 1 && nums.at(x) == nums.at(--x_)) { /*++i_;*/ continue;}
                long s = nums.at(i) + nums.at(x);
                long sum = target - s;
                int k = nums.size() - 1;
                for (int j = x + 1; j < k;){
                    //cout << "nums at j is " << nums.at(j) << endl;
                    //cout << "k is " << nums.at(k) << endl;
                    int j_ = j;
                    int k_ = k;
                    if (j > x + 1 && nums.at(j) == nums.at(--j_)) { ++j; continue;}
                    if (k < nums.size() - 1 && nums.at(k) == nums.at(++k_)) { --k; continue;}
                    long inner_sum = nums.at(j) + nums.at(k);
                    if (inner_sum == sum){
                        rez.push_back({nums.at(i), nums.at(x), nums.at(j), nums.at(k)});
                        j++;
                        k--;
                    }
                    else {
                        nums.at(j) + nums.at(k) > sum ? k-- : j++;
                    }
                }
            }
        }
        return rez;
    }
};
#endif // 4SUM_H
