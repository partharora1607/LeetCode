class Solution {
public:
    void rotate(vector<vector<int>> &matrix)
{
    // n x n matrix
    int n = matrix.size();
    int top, bottom, left, right;
    top = 0, bottom = n - 1, left = 0, right = n - 1;
    while (left < right)
    {
        top = left;
        bottom = right;
        for (int i = 0; i < right - left; i++)
        {
            int temp = matrix[top][left + i];

            matrix[top][left + i] = matrix[bottom - i][left];

            matrix[bottom - i][left] = matrix[bottom][right - i];

            matrix[bottom][right - i] = matrix[top + i][right];

            matrix[top + i][right] = temp;
        }
        left++;
        right--;
    }
}
};