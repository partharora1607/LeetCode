class Solution {
public:
vector<vector<int>> res;

void helper(vector<int> &ar, int si, int ei, int target, int sum, vector<int> &output)
{
    if (si > ei)
    {
        return;
    }

    if (sum == target)
    {
        res.push_back(output);
        return;
    }

    if (sum > target)
    {
        return;
    }

    helper(ar, si + 1, ei, target, sum, output);
    sum += ar[si];
    output.push_back(ar[si]);
    helper(ar, si, ei, target, sum, output);
    output.pop_back();
}

vector<vector<int>> combinationSum(vector<int> &ar, int target)
{
    int n = ar.size();
    vector<int> output;
    helper(ar , 0, n - 1 , target ,0 ,output);
    return res;
}
};