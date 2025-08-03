// 3 Sum problem 
#include <iostream>
#include <vector>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int j = i+1 , k = n-1;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            while(j<k){
             int   sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    result.push_back({nums[i],nums[j],nums[k]});
                    j++; k--;
                    while(j < k && nums[j] == nums[j-1]) j++;}
                    else if(sum > 0){
                        k--;
                    }
                    else{
                        j++;
                    }
                
            }
        }return result;
    } 
};