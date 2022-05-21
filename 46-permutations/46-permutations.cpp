class Solution {
public:
    void helper(vector<int> &ar, int si, int ei, vector<int> &ans, vector<vector<int>> &v, vector<int> &visited)
{
    if (ans.size() == ar.size())
    {
        v.push_back(ans);
        return;
    }

    for (int i = si; i <= ei; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            ans.push_back(ar[i]);
            helper(ar, si, ei, ans, v, visited);
            visited[i] = 0;
            ans.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> ans;
    vector<vector<int>> v;
    vector<int> visited(10, 0); // as mentioned in the questation that -10 <= nums[i] <= 10
    helper(nums, 0, nums.size() - 1, ans, v, visited);
    return v;
}
};