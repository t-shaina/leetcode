#ifndef CONTAINER_WITH_MOST_WATER_H
#define CONTAINER_WITH_MOST_WATER_H
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height){
        int max_area = 0;
        int width = 0;
        int length = height.size();
        int i = 0;
        int j = length - 1;
        while (j - i > 0){
            int level = height[i] < height[j] ? height[i] : height[j];
            int width = j - i;
            max_area = max_area > level * width ? max_area : level * width;
            height[i] > height[j] ? j-- : i++;

        }
        return max_area;

    }
};
#endif // CONTAINER_WITH_MOST_WATER_H
