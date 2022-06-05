class Solution {
public:
    
int maxProfit(vector<int> &ar)
{
    int n = ar.size(),maxans = 0,maxafter = ar[n - 1],ans =0;
    for (int i = n - 2; i >= 0; i--)
    {
        ans = maxafter - ar[i];
        maxafter = max(maxafter, ar[i]);
        maxans = max(maxans, ans);
    }
    return maxans;
}

};