class Solution {
public:
   
bool helper(vector<int> &ar, int si, int ei, vector<int> &v, int k, int target , int nessf)
{
   if (si > ei)
    {
       if(nessf == k){
        for (auto i : v)
        {
            if (i != target)
            {
                return false;
            }
        }
        return true;
       }
       return false;
    }

    for (int i = 0; i < k; i++)
    {
        if(v[i] > 0){
            if(v[i] + ar[si] > target){
                continue;
            }
            v[i] += ar[si];
            bool ans = helper(ar, si + 1, ei, v, k, target, nessf);
            if(ans == true){
                return true;
            }
            v[i] -= ar[si];
        }
        else{
            v[i] += ar[si];
            bool ans = helper(ar , si + 1, ei , v, k , target , nessf + 1);
            if(ans == true){
                return true;
            }
            v[i] -= ar[si];
            break;
        }

    }
    return false;
}
    
    bool canPartitionKSubsets(vector<int> &ar, int k)
{
    int n = ar.size();
    vector<int> v(k, 0);

    int sum = accumulate(ar.begin(), ar.end(), 0);

    if (sum % k != 0)
    {
        return false;
    }

    return helper(ar, 0, n - 1, v, k, sum / k , 0);
}
};