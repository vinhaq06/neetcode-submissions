class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][10] = {0}, col[9][10] = {0}, block[9][10] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int val = board[i][j] - '0';
                int b = (i / 3) * 3 + (j / 3);
                if (row[i][val] || col[j][val] || block[b][val]) return false;
                else {
                    row[i][val] = true;
                    col[j][val] = true;
                    block[b][val] = true;
                }
            }
        }

        return true;
    }
};
