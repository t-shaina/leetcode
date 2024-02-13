#ifndef SEARCH_IN_ROTATED_SORTED_ARRAY_H
#define SEARCH_IN_ROTATED_SORTED_ARRAY_H
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return my_search(nums, target, 0, nums.size() - 1);
    }
    int my_binary_search(vector<int>& nums, int target, int right, int left){
        if (right > left) return -1;
        int mid = right + (left - right) / 2;
        if (nums.at(mid) == target) return mid;
        if (nums.at(mid) > target) return my_binary_search(nums, target, right, mid - 1);
        else return my_binary_search(nums, target, mid + 1, left);

    }
    int search_pivot(vector<int>& nums, int right, int left){
        if (right > left) return -1;
        if (right == left) return right;
        int mid = right +  (left - right) / 2;
        if (mid < left && nums.at(mid) > nums.at(mid + 1) ) return mid;
        if (mid > right && nums.at(mid) < nums.at(mid - 1)) return mid - 1;
        if (nums.at(right) >= nums.at(mid)) return search_pivot(nums, right, mid - 1);
        return search_pivot(nums, mid + 1, left);
    }
    int my_search(vector<int>& nums, int target, int right, int left){
        int pivot = search_pivot(nums, 0, nums.size() - 1);
        if (pivot == -1) return my_binary_search(nums, target, right, left);
        if (nums.at(pivot) == target) return pivot;
        if (nums.at(right) <= target) return my_binary_search(nums, target, right, pivot - 1);
        return my_binary_search(nums, target, pivot + 1, left);
    }
};
#endif // SEARCH_IN_ROTATED_SORTED_ARRAY_H
