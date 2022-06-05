class Solution {
public:
   int longestConsecutive(vector<int> &nums)
{
    if (nums.size() <= 1)
    {
        return nums.size();
    }
    set<int> s1;
    for (int i = 0; i < nums.size(); i++)
    {
        s1.insert(nums[i]);
    }
    int ans = 1;
    int count = 1;
    set<int>::iterator next = s1.begin();
    next++;
    set<int>::iterator prev = s1.begin();
    while (next != s1.end())
    {
        if (*next - *prev == 1)
        {
            count++;
        }
        else
        {
            count = 1;
        }
        ans = max(ans, count);
        next++;
        prev++;
    }
    return ans;
}
};