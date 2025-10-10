#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0, maxLen = 1;

        // Helper lambda to expand around the center
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1; // palindrome length
        };

        for (int i = 0; i < n; i++) {
            int len1 = expand(i, i);       // Odd length
            int len2 = expand(i, i + 1);   // Even length
            int len = max(len1, len2);

            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    Solution sol;
    string result = sol.longestPalindrome(s);

    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}
