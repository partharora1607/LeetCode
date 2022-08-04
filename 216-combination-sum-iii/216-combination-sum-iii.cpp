class Solution {
public:
    vector<vector<int>> res;
    void helper(int target, int sum, int i, vector<int> &output, int k)
{
     if (target == sum)
    {
        if (output.size() == k)
        {
            res.push_back(output);
        }
        return;
    }
        
    if (i > 9)
    {
        return;
    }

    if(output.size() > k){
        return;
    }
        
    if (sum > target)
    {
        return;
    }

    helper(target, sum, i + 1, output, k);
    output.push_back(i);
    sum += i;
    helper(target, sum, i + 1, output, k);
    output.pop_back();
}

vector<vector<int>> combinationSum3(int k, int target)
{
    vector<int> output;
    helper(target, 0, 1, output, k);
    return res;
}

};