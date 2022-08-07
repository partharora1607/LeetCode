class Solution {
public:
int helper(vector<int> &ar, int si, int ei, int target, long sum , vector<vector<int>>& output)
{
    if (target == sum)
    {
        return 0;
    }

    if (si > ei)
    {
        return 100001;
    }

    if (sum > target)
    {
        return 100001;
    }

    if(output[si][sum] != -1){
        return output[si][sum];
    }

    int op1 = helper(ar, si + 1, ei, target, sum , output);
    int op2 = helper(ar, si, ei, target, sum + ar[si] , output) + 1;

    output[si][sum] = min(op1,op2);

    return min(op1, op2);
}

int coinChange(vector<int> &ar, int target)
{
    int n = ar.size();
    vector<vector<int>> output(n + 1, vector<int>(target + 1, -1));
    int ans = helper(ar, 0, n - 1, target, 0 , output);
    if (ans == 100001)
    {
        return -1;
    }
    return ans;
}
};