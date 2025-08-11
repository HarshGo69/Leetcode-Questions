#include <iostream>
#include <vector>
#include <string>
#include <unordered_set> // Added missing header for unordered_set
using namespace std;

class Solution { // Corrected class name from "Solutions" to "Solution"
public:
    int lengthOfLongestSubstring(string s) { // Corrected function name from "lenght" to "length"
        int left = 0; // Initialize left pointer to mark the start of the sliding window
        int maxLength = 0; // Initialize variable to store the length of the longest substring without repeats
        unordered_set<char> charSet; // Initialize set to store unique characters in the current window

        for (int right = 0; right < s.length(); right++) { // Loop through each character using right pointer
            while (charSet.find(s[right]) != charSet.end()) { // Check if current character is already in the set
                charSet.erase(s[left]); // Remove character at left pointer to shrink window
                left++; // Move left pointer forward to exclude the removed character
            } // Continue shrinking until the current character is not in the set

            charSet.insert(s[right]); // Add the current character to the set
            maxLength = max(maxLength, right - left + 1); // Update maxLength if current window is larger
        } // End of loop, right pointer has processed all characters

        return maxLength; // Return the length of the longest substring without repeats
    }
};