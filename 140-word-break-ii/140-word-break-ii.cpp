class Solution {
public:
    unordered_map<string, int> mymap;

vector<string> res;

void helper(string s, string output)
{
    if (s.length() == 0)
    {
        output.pop_back();
        res.push_back(output);
        return;
    }

    string s1;

    for (int i = 0; i < s.length(); i++)
    {
        s1 += s[i];
        if (mymap.count(s1))
        {
            s1 += ' ';
            helper(s.substr(i + 1), output + s1);
            s1.pop_back();
        }
    }
}

vector<string> wordBreak(string s, vector<string> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        mymap[v[i]]++;
    }
    string output;
    helper(s, output);
    return res;
}
};