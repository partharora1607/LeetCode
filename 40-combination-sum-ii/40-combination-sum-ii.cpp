class Solution {
public:
vector<vector<int>> res;

void helper(vector<int> &ar, int si, int ei, int target, int sum, vector<int> &output)
{
    if (target == sum)
    {
        res.push_back(output);
        return;
    }

    if (si > ei)
    {
        return;
    }

    if (sum > target)
    {
        return;
    }

    for (int i = si + 1; i <= ei; i++)
    {
        if (ar[i] != ar[i - 1])
        {
            helper(ar, i, ei, target, sum, output);
            break;
        }
    }

    output.push_back(ar[si]);
    helper(ar, si + 1, ei, target, sum + ar[si], output);
    output.pop_back();
}

vector<vector<int>> combinationSum2(vector<int> &ar, int target)
{
    int n = ar.size();
    sort(ar.begin(), ar.end());
    vector<int> output;
    helper(ar, 0, n - 1, target, 0, output);
    return res;
}
};