class Solution {
public:
    string getstring(char c)
{
    if (c == '2')
    {
        return "abc";
    }
    if (c == '3')
    {
        return "def";
    }
    if (c == '4')
    {
        return "ghi";
    }
    if (c == '5')
    {
        return "jkl";
    }
    if (c == '6')
    {
        return "mno";
    }
    if (c == '7')
    {
        return "pqrs";
    }
    if (c == '8')
    {
        return "tuv";
    }
    if (c == '9')
    {
        return "wxyz";
    }
    return "";
}

void helper(string digits, vector<string> &v)
{
    if (digits.length() == 0)
    {
        v.push_back("");
        return;
    }
    helper(digits.substr(1), v);
    string s = getstring(digits[0]);
    int n = v.size();
    for (int i = 0; i < s.length() - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v.push_back(v[j]);
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            v[(i * n) + j] = s[i] + v[(i * n) + j];
        }
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> v;
    if(digits.length() == 0){
        return v;
    }
    helper(digits, v);
    return v;
}
};