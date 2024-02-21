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
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        long long rez = 0;
        pair<int, int> h_border;
        pair<int, int> v_border;
        for (int i = 0; i < hFences.size() - 1; i++){
            for (int j = 0; j < vFences.size() - 1; j++){

                my_h_area(hFences, vFences, i, i, j, j, rez);
                my_v_area(hFences, vFences, i, i, j, j, rez);
                my_area(hFences, vFences, i, i, j, j, rez);
                //cout << "rez is " << rez << endl;
            }
        }
        return rez  == 0 ? -1 : rez % 1000000007;
    }
    void my_h_area(vector<int>& hFences, vector<int>& vFences, int h_first, int h_second, int v_first, int v_second, long long& rez){
        cout << "h  is " <<  h_first << h_second << endl;
        cout << "v is " <<  v_first << v_second << endl;
        if (h_second > hFences.size() - 1) return;
        //if (h_first == h_second && h_first == 0) return;
        //if (h_first == h_second || v_first == v_second) return;
        if (h_second != h_first + 1 || v_second != v_first + 1){
            long long hight = hFences.at(h_second) -  hFences.at(h_first);
            long long width =  vFences.at(v_second) -  vFences.at(v_first);
            if (hight == width) rez = rez > hight * width ?  rez : hight * width;
        }
        cout << "rez is " << rez << endl;
        my_h_area(hFences, vFences, h_first, ++h_second, v_first, v_second, rez);
    }
    void my_v_area(vector<int>& hFences, vector<int>& vFences, int h_first, int h_second, int v_first, int v_second, long long& rez){
        cout << "h  is " <<  h_first << h_second << endl;
        cout << "v is " <<  v_first << v_second << endl;
        if (v_second > vFences.size() - 1) return;
        //if (v_first == v_second && v_first == 0) return;
        //if (h_first == h_second || v_first == v_second) return;
        if (h_second != h_first + 1 && v_second != v_first + 1){
            long long hight = hFences.at(h_second) -  hFences.at(h_first);
            long long width =  vFences.at(v_second) -  vFences.at(v_first);
            if (hight == width) rez = rez > hight * width ?  rez : hight * width;
        }
        cout << "rez is " << rez << endl;
        my_v_area(hFences, vFences, h_first, h_second, v_first, ++v_second, rez);
    }
    void my_area(vector<int>& hFences, vector<int>& vFences, int h_first, int h_second, int v_first, int v_second, long long& rez){
        cout << "h  is " <<  h_first << h_second << endl;
        cout << "v is " <<  v_first << v_second << endl;
        if (v_second > vFences.size() - 1) return;
        if (h_second > hFences.size() - 1) return;
        if (h_second != h_first + 1 && v_second != v_first + 1){
            long long hight = hFences.at(h_second) -  hFences.at(h_first);
            long long width =  vFences.at(v_second) -  vFences.at(v_first);
            if (hight == width) rez = rez > hight * width ?  rez : hight * width;
        }
        cout << "rez is " << rez << endl;
        my_area(hFences, vFences, h_first, ++h_second, v_first, ++v_second, rez);
        //my_h_area(hFences, vFences, h_first, h_second, v_first, v_second, rez);
        //my_v_area(hFences, vFences, h_first, h_second, v_first, v_second, rez);
    }
};
#endif // MAXIMUM_SQUARE_AREA_BY_REMOVING_FENCES_FROM_A_FIELD_H
