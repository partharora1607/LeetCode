class Solution {
public:
 int maxSubArray(vector<int> &ar)
{
    int ans = INT_MIN;
    int sum = 0;
    for (int i = 0; i < ar.size(); i++)
    {
        sum += ar[i];
        ans = max(ans, sum);
        if (sum < 0)
        {
            sum = 0;
        }

    }
    return ans;
}
};