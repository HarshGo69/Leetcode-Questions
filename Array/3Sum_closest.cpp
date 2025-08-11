#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target_value) {
        sort(nums.begin(), nums.end());               // Sroting the number in ascending order
        int result = nums[0] + nums[1] + nums[2];     // sorting the value of sorted array

        for (int i = 0; i < nums.size() - 2; i++) {   //initializing 2 pointer method 
            int left = i + 1, right = nums.size() - 1;

            while (left < right) {        
                int sum = nums[i] + nums[left] + nums[right];     

                if (abs(target_value - sum) < abs(target_value - result)) //abs in simple term gives the mod of calculation
                    result = sum;

                if (sum == target_value) return target_value;  //moving the pointer 
                else if (sum < target_value) left++;
                else right--;
            }
        }

        return result;
    }
};