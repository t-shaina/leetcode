#ifndef MAXIMUM_SQUARE_AREA_BY_REMOVING_FENCES_FROM_A_FIELD_H
#define MAXIMUM_SQUARE_AREA_BY_REMOVING_FENCES_FROM_A_FIELD_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        long long rez = -1;
        pair<int, int> h_border;
        for (int i = 0; i < hFences.size(); i++){
            h_border = current_neghbours(hFences, i, m);
            for (int j = 0; j < vFences.size(); j++){
                pair<int, int> v_border = current_neghbours(vFences, j, n);
                if (h_border.second - h_border.first != v_border.second - v_border.first) continue;
                else rez = rez < h_border.second - h_border.first * v_border.second - v_border.first ?  h_border.second - h_border.first * v_border.second - v_border.first : rez;
                cout << "rez is " << rez << endl;
            }
        }
        return rez  == -1 ? -1 : rez % 1000000007;
    }
    pair<int, int> current_neghbours(vector<int>& v, int position, int max_position){
        pair<int, int> rez;
        if (position == 0) rez.first = 1;
        else rez.first = v.at(position - 1);
        if (position == v.size() - 1) rez.second = max_position;
        else rez.second = v.at(position + 1);
        return rez;
    }
};
#endif // MAXIMUM_SQUARE_AREA_BY_REMOVING_FENCES_FROM_A_FIELD_H
