#ifndef SUM_CLOSEST_H
#define SUM_CLOSEST_H
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int rez = 0;
        int offset = 0;
        sort(nums.begin(), nums.end(), Comp);
        int size = nums.size();
        for (int i = 0; i < size - 1 ; i++){
            cout << "nums at i is" << nums.at(i) << endl;
            int i_ = i;
            if (i > 0 && nums.at(i) == nums.at(--i_)) {continue;}
            int sum = target - (nums.at(i));
            int k = nums.size() - 1;
            for (int j = i + 1; j < k;){
                cout << "nums at j is " << nums.at(j) << endl;
                cout << "k is " << nums.at(k) << endl;
                cout << "offset is " << offset << endl;
                int j_ = j;
                int k_ = k;

                if (j > i + 1 && nums.at(j) == nums.at(--j_)) { ++j; continue;}
                if (k < nums.size() - 1 && nums.at(k) == nums.at(++k_)) { --k; continue;}
                if (nums.at(j) + nums.at(k) == sum){
                    return target;
                }
                else {
                    if (offset == 0){
                        rez = nums.at(i) + nums.at(j) + nums.at(k);
                        offset = abs(sum - nums.at(j) - nums.at(k));
                    }
                    if (abs(sum - nums.at(j) - nums.at(k)) < offset){
                        offset = abs(sum - nums.at(j) - nums.at(k));
                        rez = nums.at(i) + nums.at(j) + nums.at(k);
                    }
                    nums.at(j) + nums.at(k) > sum ? k-- : j++;
                }
                 cout << "rez is " << rez << endl;
            }
        }
        return rez;
    }
    static bool Comp(const int first, const int second){
        return first < second;
    }
};
#endif // SUM_CLOSEST_H
