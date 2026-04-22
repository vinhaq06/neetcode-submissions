class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        int temp = 0;
        while (n >= 0) {
            if (digits[n] < 9) {
                digits[n]++;
                return digits;
            }
            digits[n] = 0;
            n--;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
