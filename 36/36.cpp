class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<char,int> rows[9];
        std::unordered_map<char,int> cols[9];
        std::unordered_map<char,int> boxes[3][3];
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == '.')
                    continue;
                if (rows[i].count(board[i][j]))
                    return false;
                else
                    rows[i].insert(std::pair<char,int>(board[i][j],1));
                if (cols[j].count(board[i][j]))
                    return false;
                else
                    cols[j].insert(std::pair<char,int>(board[i][j],1));

                if (boxes[i/3][j/3].count(board[i][j]))
                {
                    return false;
                }
                else
                    boxes[i/3][j/3].insert(std::pair<char,int>(board[i][j]));
            }
        }
        return true;
    };
