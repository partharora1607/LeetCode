class Solution {
public:
    int strStr(string s1, string s2)
{
    if (s2.length() > s1.length())
    {
        return -1;
    }
    if (s1.substr(0, s2.length()) == s2)
    {
        return 0;
    }
    int ans =  strStr(s1.substr(1), s2);
    if(ans != -1){
        return ans + 1;
    }
    return ans;
}
};