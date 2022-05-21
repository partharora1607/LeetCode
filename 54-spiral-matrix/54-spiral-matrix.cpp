class Solution {
public:
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int nCols = matrix[0].size();
    int nRows = matrix.size();

    int n = nCols * nRows;
    int count = 0;

    int left = 0, top = 0;

    while (count < n)
    {
        for (int j = left; j < nCols && count < n; j++)
        {
            ans.push_back(matrix[top][j]);
            count++;
        }
        top++;
        for (int i = top; i < nRows && count < n; i++)
        {
            ans.push_back(matrix[i][nCols - 1]);
            count++;
        }
        nCols--;
        for (int j = nCols - 1; j >= left && count < n; j--)
        {
            ans.push_back(matrix[nRows - 1][j]);
            count++;
        }
        nRows--;
        for (int i = nRows - 1; i >= top && count < n; i--)
        {
            ans.push_back(matrix[i][left]);
            count++;
        }
        left++;
    }
    return ans;
}
};