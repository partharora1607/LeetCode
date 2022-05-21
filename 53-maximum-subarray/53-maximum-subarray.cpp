class Solution {
public:
int maxSubArray(vector<int> &ar)
{
    int ans = -100000;
    int sum = 0;
    for (int i = 0; i < ar.size(); i++)
    {
        sum += ar[i];
        ans = max(ans, sum);
        if (sum >= 0)
        {
            ans = max(ans, sum);
        }
        else
        {
            sum = 0;
        }
    }
    return ans;
}

};