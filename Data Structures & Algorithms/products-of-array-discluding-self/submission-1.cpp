class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> newArr(n);
        int index = 0;
        while (index < n) {
            int sum = 1;
            for (int i = 0; i < n; i++) {
                if (i == index) continue;
                sum *= nums[i];
            }
            newArr[index++] = sum;
        }
        return newArr;
    }
};
