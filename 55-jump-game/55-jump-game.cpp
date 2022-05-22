class Solution {
public:
bool canJump(vector<int> &ar)
{
    int n = ar.size();
    if (n <= 1)
    {
        return true;
    }
    vector<int> ans(n + 1);
    ans[0] = 1;
    ans[1] = 1;
    bool flag = false;
    for (int i = 2; i <= n; i++)
    {
        flag = false;
        for (int j = 1; j <= ar[n - i]; j++)
        {
            if (ans[i - j] == 1)
            {
                ans[i] = 1;
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            ans[i] = 0;
        }
    }
    return ans[n];
}
};