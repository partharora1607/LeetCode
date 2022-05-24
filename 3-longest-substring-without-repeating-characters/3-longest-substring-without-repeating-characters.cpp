class Solution {
public:
int lengthOfLongestSubstring(string s)
{
    unordered_set<int> set1;
    int i = 0, ans = 0;
    for (int j = 0; j < s.length(); j++)
    {
        while (set1.count(s[j]) == 1)
        {
            set1.erase(s[i++]);
        }
        set1.insert(s[j]);
        ans = max(ans, j - i + 1);
    }
    return ans;
}
};