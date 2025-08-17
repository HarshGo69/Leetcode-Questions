#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) return 0;
        int i = 0, sign = 1, ans = 0;
        // Skip leading spaces
        while (i < s.size() && s[i] == ' ') i++;
        // Handle sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        // Process digits
        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';
            // Check for overflow
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            ans = ans * 10 + digit;
            i++;
        }
        return sign * ans;
    }
};