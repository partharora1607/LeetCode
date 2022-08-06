class Solution {
public:
bool helper(vector<int> &ar, int si, int ei, int target, int sum, vector<vector<int>> &output)
{
    if (si > ei)
    {
        if (sum == target)
        {
            return true;
        }
        return false;
    }

    if (sum > target)
    {
        return false;
    }

    if (output[si][sum] != -1)
    {
        return output[si][sum];
    }

    bool op1 = helper(ar, si + 1, ei, target, sum, output);
    bool op2 = helper(ar, si + 1, ei, target, sum + ar[si], output);

    output[si][sum] = op1 || op2;
    return op1 || op2;
}

bool canPartition(vector<int> &ar)
{
    int sum = 0;
    int n = ar.size();
    for (int i = 0; i < n; i++)
    {
        sum += ar[i];
    }
    if(sum % 2 != 0){
        return false;
    }
    int target = sum / 2;
    vector<vector<int>> output(n + 1, vector<int>(target + 1, -1));
    return helper(ar, 0, n - 1, target, 0, output);
}

};