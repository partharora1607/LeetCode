class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words)
{
    int len = words[0].size();
    int no_of_words = words.size();
    int total = len * no_of_words;
    if (total > s.length())
    {
        return {};
    }
    vector<int> result;
    unordered_map<string, int> mymap;
    for (int i = 0; i < words.size(); i++)
    {
        mymap[words[i]]++;
    }

    for (int i = 0; i < s.length() - total + 1; i++)
    {
        unordered_map<string, int> mymap2;
        for (int j = i; j < i + total; j += len)
        {
            string curr = s.substr(j, len);
            if (mymap.find(curr) == mymap.end())
            {
                break;
            }
            mymap2[curr]++;
            if (mymap2[curr] > mymap[curr])
            {
                break;
            }
        }
        if (mymap2 == mymap)
        {
            result.push_back(i);
        }
    }
    return result;
}
};