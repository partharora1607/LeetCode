class Solution {
public:
vector<vector<int>> generateMatrix(int n)
{
    int top = 0, left = 0, bottom = n - 1, right = n - 1;
    vector<vector<int>> v(n, vector<int>(n));
    int val = 1;
    while (left <= right)
    {
        for (int j = left; j <= right; j++)
        {
            v[top][j] = val++;
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            v[i][right] = val++;
        }
        right--;
        for (int j = right; j >= left; j--)
        {
            v[bottom][j] = val++;
        }
        bottom--;
        for (int i = bottom; i >= top; i--)
        {
            v[i][left] = val++;
        }
        left++;
    }
    return v;
}
};