class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        int l = 0, r = len - 1;
        char temp = ' ';
        while (l < r) {
            temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++;
            r--;
        }
    }
};