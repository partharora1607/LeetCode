class Solution {
public:
   int countConsistentStrings(string allowed, vector<string> &words)
{
    unordered_set<char> myset;
    for (int i = 0; i < allowed.size(); i++)
    {
        myset.insert(allowed[i]);
    }
    int ans = 0;
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words[i].size(); j++)
        {
            if (myset.count(words[i][j]) == 0)
            {
                ans -= 1;
                cout << true << endl;
                break;
            }
        }
        ans += 1;
    }
    return ans;
}
};