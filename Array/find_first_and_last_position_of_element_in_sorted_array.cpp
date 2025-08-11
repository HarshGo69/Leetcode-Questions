// Use Two binary searches for the left most and rigt most 
#include <iostream>
#include <vector> 
using namespace std;   //so that we do not have to use std::
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) { 
        vector<int> res = {-1, -1};         //given to take the condition 
        int start = 0, end = nums.size() - 1;
        while (start <= end) {                    // for finding the leftmost element 
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                res[0] = mid;                     //for example nums = [5,7,7,8,8,10], target = 8 ..element was found on the 4 indexing so res[0] = 4
                end = mid - 1;
            }
        }

        if (res[0] == -1) return res;     //for the rightmost element 
        start = res[0];
        end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                res[1] = mid;
                start = mid + 1;
            }
        }

        return res;
    }
};