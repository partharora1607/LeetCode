class Solution {
public:
    string longestPalindrome(string s)
{
    int fsi = 0;
    int fei = 0;

    int n = s.length();
    int ans = 0;
    int i = 0;
    while (i < n)
    { // i++
        // odd maximum
        int start, end;
        start = i - 1;
        end = i + 1;
        while (start >= 0 && end < n && s[start] == s[end])
        {
            start--;
            end++;
        }
        start++;
        end--;
        int size = end - start + 1;
        if (size > ans)
        {
            ans = size;
            fsi = start;
            fei = end;
        }
        i++;
    }
    int val1 = 0, var2 = 1;
    while (val1 >= 0 && var2 < n)
    {
        // even length
        if(s[val1] == s[var2])
        {
            int start = val1 - 1;
            int end = var2 + 1;
            while (start >= 0 && end < n && s[start] == s[end])
            {
                start--;
                end++;
            }
            start++;
            end--;
            int size = end - start + 1;
            if (size > ans)
            {
                ans = size;
                fsi = start;
                fei = end;
            }
        }
        val1++;
        var2++;
    }
    return s.substr(fsi, fei - fsi + 1);
}
};