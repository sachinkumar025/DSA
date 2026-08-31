class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int index) {
        // Word complete ho gaya
        if (index == word.size())
            return true;

        // Boundary check
        if (r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size() ||
            board[r][c] != word[index])
            return false;

        // Current cell ko visited mark karo
        char temp = board[r][c];
        board[r][c] = '#';

        // 4 directions
        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);

        // Backtracking: cell ko wapas original karo
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }
};