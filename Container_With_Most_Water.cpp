//Conatiner with most water with explaination
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {                     // function 
        int left = 0;                                            
        int right = height.size() - 1;                    // As the size starts from 1 but indexing from 0 
        int mostWater = 0;                                
        while (left < right) {                            //when indexing of left is less than right 
            int initialWater = min(height[left], height[right]) * (right - left); // formula of area of rectangle a = l* b but the water would be holded to the height of minimum boundry otherwise water would spill thats why we take the minumum and right - left for the width of the rectangle 
            mostWater = max(mostWater, initialWater); 
            if (height[left] <= height[right]) {     
                left++;
            } else {
                right--;
            }
        }
        return mostWater;
    }
};