class Solution {
public:
   void helper(int n, vector<string> &v, string s, int openN, int closedN)
{
    if (s.length() == 2 * n)
    {
        v.push_back(s);
        return;
    }

    if (openN < n)
    {
        s.push_back('(');
        helper(n, v, s, openN + 1, closedN);
        s.pop_back();
    }

    if (closedN < openN)
    {
        s.push_back(')');
        helper(n, v, s, openN, closedN + 1);
        s.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> v;
    string s = "";
    helper(n, v, s, 0, 0);
    return v;
}
};