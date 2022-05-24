class Solution {
public:
int lengthOfLongestSubstring(string s)
{
    unordered_map<int, int> mymap;
    int ans=0,i=0,j=0,n = s.length();
    while (j < n)
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
                mymap.erase(s[i++]);
            }
            mymap[s[j]]++;
        }
        j++;
    }
    return ans;
}
};