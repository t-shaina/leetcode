#ifndef FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H
#define FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> rez;
        pair<int, int> pair;

    }
    int my_search(vector<int>& nums, pair<int, int>& pair, int target, int right, int left){
        if (right > left) return -1;
        //if (right == left)
        int mid = right + (left - right) / 2;
        if (nums.at(mid) == target) {

            if (nums.at(mid - 1) == target){
                my_search(nums, pair, target, right, mid - 1);
            }
            else if (pair.first < nums.at(mid)) pair.first = mid;
            if (nums.at(mid + 1) == target){
                my_search(nums, pair, target,  mid + 1, left);
            }
            else if (pair.second < nums.at(mid)) pair.second = mid;
        }
        if (nums.at(mid) > target)  return my_search(nums, pair, target, right, mid - 1);
        if (nums.at(mid) < target) return my_search(nums, pair, target, mid + 1, left);
    }

};

#endif // FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H
