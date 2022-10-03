class Solution {
public:
    vector<string> commonChars(vector<string> &words)
{
	vector<int> freq(26, INT_MAX);
    vector<int> visited(26 , 0);
	for (int i = 0; i < words.size(); i++)
	{
		string s = words[i];
		unordered_map<char, int> mymap;
		for (int j = 0; j < words[i].size(); j++)
		{
			mymap[s[j]]++;
		}
		auto it = mymap.begin();
		while (it != mymap.end())
		{
			int val = it->first - 'a';
			freq[val] = min(it->second, freq[val]);
            visited[val]++;
			it++;
		}
	}
	vector<string> ans;
	for (int i = 0; i < freq.size(); i++)
	{
		if (freq[i] != INT_MAX && visited[i] == words.size())
		{
			while (freq[i] > 0)
			{
				string res = "";
				res += i + 'a';
				ans.push_back(res);
				freq[i]--;
			}
		}
	}
	return ans;
}
};