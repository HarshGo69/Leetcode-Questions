#include <string>

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        
        while (i >= 0 || j >= 0 || carry) {
            carry += (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0);
            ans += (carry % 2) + '0';
            carry /= 2;
        }
        
        return string(ans.rbegin(), ans.rend());
    }
};