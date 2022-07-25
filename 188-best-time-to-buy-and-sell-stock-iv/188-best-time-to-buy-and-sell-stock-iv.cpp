class Solution {
public:
int maxProfit(int k, vector<int> &ar)
{
    int n = ar.size();
    int m = k + 1;
    
    if(n <= 1){
        return 0;
    }
    
    vector<vector<int>> output(k + 1, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        output[i][0] = 0;
    }

    for (int j = 0; j < n; j++)
    {
        output[0][j] = 0;
    }

    for (int i = 1; i < m; i++)
    {
        int ans = INT_MIN;
        for (int j = 1; j < n; j++)
        {
            ans = max(ans , output[i - 1][j - 1] - ar[j - 1]);
            output[i][j] = max(output[i][j - 1] , ans + ar[j]);
        }
    }

    return output[k][n - 1];
}
};