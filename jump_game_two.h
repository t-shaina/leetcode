#ifndef JUMP_GAME_TWO_H
#define JUMP_GAME_TWO_H
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        if ( nums.size() == 1) {
             return 0;
        }
        int rez = 0;
        vector<int> jumps;
        my_jump(nums, 0, jumps, rez);
         if (jumps.empty()) return 0;
        sort(jumps.begin(), jumps.end());
        cout << "jumps is " << endl;
        for (auto i = jumps.begin(); i != jumps.end(); ++i)
            cout << *i;
        cout << endl;
        return *jumps.begin();

    }
    void my_jump (vector<int>& nums, int position, vector<int>& jumps, int& rez){
        int i = position;
        //cout << "i is " << i << "value is " << nums.at(i) << endl;
        cout << "rez is " << rez << endl;
        if (i < nums.size()){
            if (i < nums.size() - 1){
                if (nums.at(i) == 0) {--rez; return;}
                else {
                    for (int j = 1; j < nums.at(i) + 1; ++j){
                        rez++;
                        my_jump(nums, i + j,  jumps, rez);
                    }
                    rez--;
                }
            }
            else {jumps.push_back(rez); --rez; return;}
        }
        else {--rez; return;}

    }
};
#endif // JUMP_GAME_TWO_H
