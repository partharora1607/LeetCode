class Solution {
public:
    int strStr(string s1, string s2)
{
    if (s2.size() == 0)
    {
        return 0;
    }
    for (int i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] == s2[0] && s1.substr(i, s2.length()) == s2)
        {
            return i;
        }
    }
    return -1;
}
};