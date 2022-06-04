class Solution {
public:
vector<vector<string>> v;

void helper(const int n, unordered_set<int> &cols, unordered_set<int> &posdiagonal, unordered_set<int> &negdiagonal, vector<vector<char>> &matrix,int row)
{
    if (row == n)
    {
        vector<string> res;
        for (int i = 0; i < matrix.size(); i++)
        {
            string s;
            for (int j = 0; j < matrix[i].size(); j++)
            {
                s += matrix[i][j];
            }
            res.push_back(s);
        }
        v.push_back(res);
    }

    for (int c = 0; c < n; c++)
    {
        if (cols.count(c) == 1 || posdiagonal.count(row + c) == 1 || negdiagonal.count(row - c) == 1)
        {
            continue;
        }
        cols.insert(c);
        posdiagonal.insert(row + c);
        negdiagonal.insert(row - c);
        matrix[row][c] = 'Q';
        helper(n, cols, posdiagonal, negdiagonal, matrix, row + 1);
        cols.erase(c);
        posdiagonal.erase(row + c);
        negdiagonal.erase(row - c);
        matrix[row][c] = '.';
    }
}

vector<vector<string>> solveNQueens(int n)
{
    unordered_set<int> cols;
    unordered_set<int> posdiagonal; // r + c
    unordered_set<int> negdiagonal; // r - c
    vector<vector<char>> matrix(n, vector<char>(n, '.'));
    helper(n, cols, posdiagonal, negdiagonal, matrix, 0);
    return v;
}
};