class Solution {
public:
   vector<vector<int>> transpose(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> res(n, vector<int>(m));
    int i1 = 0, j1 = 0;
    for (int i = 0; i < m; i++)
    {
        i1 = 0;
        for (int j = 0; j < n; j++)
        {
            res[i1++][j1] = matrix[i][j];
        }
        j1++;
    }
    return res;
}
};