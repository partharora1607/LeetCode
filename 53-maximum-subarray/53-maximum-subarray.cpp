class Solution {
public:
   int maxSubArray(vector<int> &ar)
{
    int ans = INT_MIN;
    int sum = 0;
    for (int i = 0; i < ar.size(); i++)
    {
        sum += ar[i];
        if (sum >= 0)
        {
            ans = max(ans, sum);
        }
        else
        {
            ans = max(ans, sum);
            sum = 0;
        }
    }
    return ans;
}
};