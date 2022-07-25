class Solution {
public:
vector<vector<string>> res;

bool isPalindrome(string s)
{
    int n = s.length();
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++, j--;
    }
    return true;
}

void helper(string s, vector<string>& v)
{
    if(s.length() == 0){
        res.push_back(v);
        return;
    }

    for (int i = 0; s[i] != '\0'; i++)
    {
        string s1 = s.substr(0, i + 1);
        bool ans = isPalindrome(s1);
        if (ans)
        {
            v.push_back(s1);
            helper(s.substr(i + 1),v);
            v.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<string> v; 
    helper(s , v);
    return res;
}
};