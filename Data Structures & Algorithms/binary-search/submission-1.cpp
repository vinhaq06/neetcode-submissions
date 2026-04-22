class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int mid = (l + r) / 2;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] > target) r--;
            else if (nums[mid] < target) l++;
            else return mid;
        }
        return -1;
    }
};
