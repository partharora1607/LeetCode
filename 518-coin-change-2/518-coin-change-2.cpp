class Solution {
public:
int helper(vector<int> &ar, int si, int ei, int target, int sum, vector<vector<int>> &output)
{

    if (sum == target)
    {
        return 1;
    }

    if (si > ei)
    {
        return 0;
    }

    if (sum > target)
    {
        return 0;
    }

    if(output[si][sum] != -1){
        return output[si][sum];
    }

    int op1 = helper(ar, si + 1, ei, target, sum , output);
    int op2 = helper(ar, si, ei, target, sum + ar[si] , output);

    output[si][sum] = op1 + op2;

    return op1 + op2;
}

int change(int amount, vector<int> &ar)
{
    int n = ar.size();
    vector<vector<int>> output(n + 1, vector<int>(amount + 1, -1));
    return helper(ar, 0, n - 1, amount, 0, output);
}

};