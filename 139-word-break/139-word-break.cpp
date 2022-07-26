class Solution {
public:
    bool helper(string s, int si, unordered_map<string, int> &mymap , vector<int> &output)
{
    int n = s.length();

    if (si >= n)
    {
        return true;
    }

    if(output[si] != -1){
        return output[si];
    }
        
    string s1;

    for (int i = si; i < n; i++)
    {
        s1 += s[i];
        if (mymap.count(s1) == 1 && helper(s, i + 1, mymap , output))
        {
            output[si] = true;
            return true;
        }
    }
    output[si] = false;
        
    return false;
}

bool wordBreak(string s, vector<string> &v)
{
    unordered_map<string, int> mymap;
    int n = s.length();
    vector<int> output(n + 1 , -1);
    for (int i = 0; i < v.size(); i++)
    {
        mymap[v[i]]++;
    }
    return helper(s, 0, mymap , output);
}
};