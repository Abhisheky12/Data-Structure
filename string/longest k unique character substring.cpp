#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestKSubstr(string str, int k) {
        vector<int> count(256, 0);
        int unique = 0, max_len = -1, first = 0, second = 0;
        
        // Traverse the string using the sliding window technique
        while (second < str.size()) {
            // Add the current character to the window
            if (count[str[second]] == 0) {
                unique++;
            }
            count[str[second]]++;
            second++;
            
            // If unique characters exceed K, shrink the window from the left
            while (unique > k) {
                count[str[first]]--;
                if (count[str[first]] == 0) {
                    unique--;
                }
                first++;
            }
            
            // If the window has exactly K unique characters, update the maximum length
            if (unique == k) {
                max_len = max(max_len, second - first);
            }
        }
        
        return max_len;
    }
};

int main() {
    Solution sol;
    string str = "aabacbebebe";
    int k = 3;
    
    cout << sol.longestKSubstr(str, k) << endl; // Output: 7 ("cbebebe")
    
    return 0;
}