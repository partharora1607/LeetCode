class Solution {
public:
int lengthOfLongestSubstring(string s)
{
    unordered_map<int, int> mymap;
    int ans = 0;
    int i = 0;
    int j = 0;
    while (j < s.length())
    {
        if (mymap.count(s[j]) == 0)
        {
            mymap[s[j]]++;
            ans = max(ans , j - i + 1);
        }
        else
        {
            while (mymap.count(s[j]) == 1)
            {
                mymap.erase(s[i]);
                i++;
            }
            mymap[s[j]]++;
        }
        j++;
    }
    return ans;
}
};