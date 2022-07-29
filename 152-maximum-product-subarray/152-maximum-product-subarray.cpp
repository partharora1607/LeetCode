class Solution {
public:
int maxProduct(vector<int> &ar)
{
    int n = ar.size();
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return ar[0];
    }
    vector<int> helper(n);
    int i = n - 1;
    bool flag = false;
    while (i >= 0) // i++
    {
        helper[i] = flag;
        if (ar[i] < 0)
        {
            flag = true;
        }
        i--;
    }
    int ans = 1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] > 0)
        {
            ans *= ar[i];
            res = max(res , ans);
        }
        else if (ar[i] == 0)
        {
            if(ans > 1){
                res = max(res, ans);
            }
            ans = 1;
        }
        else
        {
            if (helper[i] == 1 || ans < 0)
            {
                ans *= ar[i];
                res = max(res , ans);
            }
            else
            {
                ans = 1;
            }
        }
    }
    ans = 1;
    flag = false;
    
    for(int i = 0;i<n;i++){
        helper[i] = flag;
        if(ar[i] < 0){
            flag = true;
        }
    }
    
    for(int i = n - 1 ;i >=0 ;i--){
         if (ar[i] > 0)
        {
            ans *= ar[i];
            res = max(res , ans);
        }
        else if (ar[i] == 0)
        {
            if(ans > 1){
                res = max(res, ans);
            }
            ans = 1;
        }
        else
        {
            if (helper[i] == 1 || ans < 0)
            {
                ans *= ar[i];
                res = max(res , ans);
            }
            else
            {
                ans = 1;
            }
        }
    }
    return res;
}
};