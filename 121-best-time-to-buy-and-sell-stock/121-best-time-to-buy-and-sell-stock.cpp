class Solution {
public:
    
int maxProfit(vector<int> &ar)
{
    if(ar.size() == 1){
        return 0;
    }
    int n = ar.size();
    int maxans = 0;
    int maxafter = ar[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        int ans = maxafter - ar[i];
        maxafter = max(maxafter, ar[i]);
        maxans = max(maxans, ans);
    }
    return maxans;
}

};