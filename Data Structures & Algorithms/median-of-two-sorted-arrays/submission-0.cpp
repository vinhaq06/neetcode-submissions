class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sorted;
        int m = nums1.size();
        int n = nums2.size();
        int idx1 = 0;
        int idx2 = 0;
        while (idx1 < m && idx2 < n) {
            if (nums1[idx1] < nums2[idx2]) {
                sorted.push_back(nums1[idx1]);
                idx1++;
            }
            else {
                sorted.push_back(nums2[idx2]);
                idx2++;
            }
        }

        while (idx1 < m) sorted.push_back(nums1[idx1++]);
        while (idx2 < n) sorted.push_back(nums2[idx2++]);

        int len = m + n;

        if (len % 2 == 0) {
            return (sorted[len / 2 - 1] + sorted[len / 2]) / 2.0;
        }

        else return sorted[len / 2];
    }
};
