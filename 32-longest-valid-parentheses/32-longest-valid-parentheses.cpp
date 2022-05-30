class Solution {
public:
    int longestValidParentheses(string s)
{
    stack<int> index;
    index.push(-1);
    int ans = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
        {
            index.push(i);
        }
        else
        {
            index.pop();
            if (index.empty())
            {
                index.push(i);
            }
            else
            {
                ans = max(ans, i - index.top());
            }
        }
    }
    return ans;
}
};