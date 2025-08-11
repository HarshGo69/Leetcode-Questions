#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Initialize left pointer of the sliding window
        int start_basket = 0;
        // Track the maximum length of a subarray with at most 2 fruit types
        int maxLenght = 0;
        // Hash map to store fruit types and their counts in the current window
        unordered_map<int, int> basket;

        // Loop through the array using the right pointer (end)
        for (int end = 0; end < fruits.size(); ++end) {
            // Add the current fruit to the basket and increment its count
            basket[fruits[end]]++;

            // If basket has more than 2 fruit types, shrink the window
            while (basket.size() > 2) {
                // Decrease the count of the fruit at the start of the window
                basket[fruits[start_basket]]--;
                // If the count becomes 0, remove the fruit type from the basket
                if (basket[fruits[start_basket]] == 0) {
                    basket.erase(fruits[start_basket]);
                }
                // Move the left pointer to shrink the window
                start_basket++;
            }

            // Update the maximum length of the valid window
            maxLenght = max(maxLenght, end - start_basket + 1);
        }

        // Return the length of the longest subarray with at most 2 fruit types
        return maxLenght;
    }
};