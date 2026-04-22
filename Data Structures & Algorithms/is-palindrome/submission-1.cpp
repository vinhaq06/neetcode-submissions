class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 1) return true;
        string final;
        for (char c:s) {
            if (isalnum(c)) final += tolower(c);

        }
        int l = 0, r = final.size() - 1;
        while (l < r) {
            if (final[l] != final[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
