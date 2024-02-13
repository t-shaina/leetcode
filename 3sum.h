#ifndef SUM_H
#define SUM_H
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rez;
        multiset<int> nums_set;
        int size = nums.size();
        for (int i = 0; i < size - 2 ; i++){
            cout << "i is " << i << endl;
            nums_set.insert(nums.begin() + i + 1, nums.end());
            int sum = 0 - (nums.at(i));
            for (auto j = nums_set.begin(); j != nums_set.end(); ++j){
                 cout << "*j is " << *j ;
                if(sum )
                if (nums_set.count(sum - (*j)) > 0)
                    rez.push_back({nums.at(i), *j, sum - (*j)});
                 cout << endl;
            }
        }
        return rez;
    }*/
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rez;
        sort(nums.begin(), nums.end(), Comp);
        int size = nums.size();
        for (int i = 0; i < size - 1 ; i++){
            cout << "nums at i is" << nums.at(i) << endl;
            int i_ = i;
            if (i > 0 && nums.at(i) == nums.at(--i_)) { /*++i_;*/ continue;}
            int sum = 0 - (nums.at(i));
            int k = nums.size() - 1;
            for (int j = i + 1; j < k;){
                cout << "nums at j is " << nums.at(j) << endl;
                cout << "k is " << nums.at(k) << endl;
                int j_ = j;
                int k_ = k;
                if (j > i + 1 && nums.at(j) == nums.at(--j_)) { ++j; continue;}
                if (k < nums.size() - 1 && nums.at(k) == nums.at(++k_)) { --k; continue;}
                if (nums.at(j) + nums.at(k) == sum){
                    rez.push_back({nums.at(i), nums.at(j), nums.at(k)});
                    j++;
                    k--;
                }
                else {
                    nums.at(j) + nums.at(k) > sum ? k-- : j++;
                }
            }
        }
        return rez;
    }
    static bool Comp(const int first, const int second){
        return first < second;
    }
};

#endif // SUM_H
