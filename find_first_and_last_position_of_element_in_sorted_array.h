#ifndef FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H
#define FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector{-1, -1};
        vector<int> rez;
        pair<int, int> pair;
        my_search(nums, pair, target, 0, nums.size() - 1);
        rez.push_back(pair.first);
        rez.push_back(pair.second);
        return rez;

    }
    void my_search(vector<int>& nums, pair<int, int>& pair, int target, int left, int right){
        if (left > right) {pair.first = -1; pair.second = -1; return;}
        //if (right == left) {}
        int mid = left + (right - left) / 2;
        if (nums.at(mid) == target) {
            if (mid > left){
                if (nums.at(mid - 1) != target){
                    pair.first = mid;
                }
                else pair.first = my_left_search(nums, target, left, mid - 1);
            }
            else pair.first = mid;
            if (mid < right){
                if ( nums.at(mid + 1) != target){
                    pair.second = mid;
                }
                else pair.second = my_right_search(nums, target, mid + 1, right);
            }
            else pair.second = mid;
            return;
        }
        if (nums.at(mid) > target)  return my_search(nums, pair, target, left, mid - 1);
        if (nums.at(mid) < target) return my_search(nums, pair, target, mid + 1, right);
    }
    int my_left_search(vector<int>& nums, int target, int left, int right){
        int mid = left + (right - left) / 2;
        if (mid == left) return nums.at(mid) == target ? mid : mid + 1;
        if (nums.at(mid) == target) {
            if (nums.at(mid - 1) != target){
                //cout << "mid in left search is " << mid << endl;
                return  mid;
            }
            else return my_left_search(nums, target, left, mid - 1);
        }
        else if (nums.at(mid) > target) return my_left_search(nums, target, left, mid - 1);
        else  return my_left_search(nums, target, mid + 1, right);
    }
    int my_right_search(vector<int>& nums, int target, int left, int right){
        int mid = left + (right - left) / 2;
        if (mid == right) return nums.at(mid) == target ? mid  : mid - 1;;
        if (nums.at(mid) == target) {
            if (nums.at(mid + 1) != target){
                //cout << "mid in right search is " << mid << endl;
                return  mid;
            }
            else return  my_right_search(nums, target, mid + 1, right);
        }
        else if (nums.at(mid) > target)  return my_right_search(nums, target, left, mid - 1);
        else return my_right_search(nums, target, mid + 1, right);
    }

};

#endif // FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H
