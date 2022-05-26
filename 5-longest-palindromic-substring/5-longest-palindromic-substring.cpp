class Solution {
public:
   string longestPalindrome(string s)
{
    int ans = 0;
    int fsi = 0;
    int fei = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        // odd
        int si = i - 1, ei = i + 1;
        int count = 1;
        while (si >= 0 && ei <= s.length() && s[si] == s[ei])
        {
            count += 2;
            si--;
            ei++;
        }
        if (count > ans)
        {
            ++si;
            --ei;
            ans = count;
            fsi = si;
            fei = ei;
        }
        // even        
        if (i + 1 < s.length() && s[i] == s[i + 1])
        {
            si = i - 1;
            ei = i + 1;
            ei++;
            count = 2;
            while (si >= 0 && ei <= s.length() && s[si] == s[ei])
            {
                count += 2;
                si--;
                ei++;
            }
            if (count > ans)
            {
                ++si;
                --ei;
                ans = count;
                fsi = si;
                fei = ei;
            }
        }
    }
    return s.substr(fsi , fei - fsi + 1);
}
};