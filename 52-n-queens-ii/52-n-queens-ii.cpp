class Solution {
public:
    int ans = 0;
map<vector<vector<char>>, int> mymap;

void helper(int n, unordered_set<int> &cols, unordered_set<int> &posdiagonal, unordered_set<int> &negdiagonal, vector<vector<char>> &matrix, int row)
{
    if (row == n)
    {
        if (mymap.count(matrix) == 0)
        {
            ans++;
        }
        return;
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

int totalNQueens(int n)
{
    unordered_set<int> cols;
    unordered_set<int> posdiagonal; // r + c
    unordered_set<int> negdiagonal; // r - c
    vector<vector<char>> matrix(n, vector<char>(n, '.'));
    helper(n, cols, posdiagonal, negdiagonal, matrix, 0);
    return ans;
}
};