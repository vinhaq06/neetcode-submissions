class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> res;
        unordered_map<int, int> nextGreater;
        for (int x : nums2) {
            while (!st.empty() && x > st.top()) {
                nextGreater[st.top()] = x;
                st.pop();
            }

            st.push(x);
        }

        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        for (int i = 0; i < nums1.size(); i++) {
            res.push_back(nextGreater[nums1[i]]);
        }

        return res;
    }
};