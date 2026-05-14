class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int n = s.length();
        int count = 0;
        int r = 0;
        while (r < n) {
            for (int i = l; i < r; i++) {
                if (s[i] == s[r]) {
                    l = i + 1;
                    break;
                }
            }
            count = max(count, r - l + 1);
            r++;
        }

        return count;
    }
};
