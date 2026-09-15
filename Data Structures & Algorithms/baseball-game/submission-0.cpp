class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> point;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                int top = point.top();
                point.pop();
                int newTop = top + point.top();
                point.push(top);
                point.push(newTop);
            }
            else if (operations[i] == "C") {
                point.pop();
            }
            else if (operations[i] == "D") {
                point.push(point.top() * 2);
            }
            else {
                point.push(stoi(operations[i]));
            }
        }

        int res = 0;
        while (!point.empty()) {
            res += point.top();
            point.pop();
        }

        return res;
    }
};