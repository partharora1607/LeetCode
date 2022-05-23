class Solution {
public:
bool searchMatrix(vector<vector<int>> &v, int target)
{
    int m = v.size();
    int n = v[0].size();
    for (int i = 0; i < m; i++)
    {
        int si = v[i][0];
        int ei = v[i][n - 1];
        if (target >= si && target <= ei)
        {
            si = 0, ei = n - 1;
            while (si <= ei)
            {
                int mid = (si + ei) / 2;
                if (v[i][mid] == target)
                {
                    return true;
                }
                else if (target > v[i][mid])
                {
                    si = mid + 1;
                }
                else
                {
                    ei = mid - 1;
                }
            }
            return false;
        }
    }
    return false;
}
};