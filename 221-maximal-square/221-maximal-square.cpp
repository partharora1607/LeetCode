class Solution {
public:
    int maximalSquare(vector<vector<char>> &ar)
{

    int m = ar.size();
    int n = ar[0].size();

    int ans = 0;

    vector<vector<int>> output(m, vector<int>(n));

    for (int j = 0; j < n; j++)
    {
        int val = ar[0][j] - '0';
        if (val == 1)
        {
            ans = 1;
            output[0][j] = 1;
        }
        else
        {
            output[0][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int val = ar[i][0] - '0';
        if (val == 1)
        {
            output[i][0] = 1;
            ans = 1;
        }
        else
        {
            output[i][0] = 0;
        }
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int val = ar[i][j] - '0';
            if (val == 0)
            {
                output[i][j] = 0;
            }
            else
            {
                int op1 = output[i][j - 1];
                int op2 = output[i - 1][j - 1];
                int op3 = output[i - 1][j];

                output[i][j] = min({op1, op2, op3}) + 1;
                ans = max(ans, output[i][j]);
            }
        }
    }

    return ans * ans;
}
};