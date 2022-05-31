class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words)
{
    int no_of_words = words.size();
    int len = words[0].length();
    unordered_map<string, int> mymap;
    vector<int> result;
    if (len * no_of_words > s.length())
    {
        return result;
    }
    for (int i = 0; i < words.size(); i++)
    {
        mymap[words[i]]++;
    }
    for (int i = 0; i <= s.length() - (no_of_words * len); i++)
    {
        unordered_map<string, int> usemap;
        for (int j = i; j < i + (no_of_words * len); j += len)
        {
            string curr = s.substr(j, len);
            if (mymap.find(curr) == mymap.end())
            {
                break;
            }
            usemap[curr]++;
            if (usemap[curr] > mymap[curr])
            {
                break;
            }
        }
        if (mymap == usemap)
        {
            result.push_back(i);
        }
    }
    return result;
}

};