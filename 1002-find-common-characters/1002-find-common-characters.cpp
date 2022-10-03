class Solution {
public:
    vector<string> commonChars(vector<string> &words)
{
	vector<int> visited(26, 0);
	vector<int> freq(26, INT_MAX);
	for (int i = 0; i < words.size(); i++)
	{
		string s = words[i];
		unordered_map<char, int> mymap;
		for (int j = 0; j < s.size(); j++)
		{
			mymap[s[j]]++;
		}
		auto it = mymap.begin();
		while (it != mymap.end())
		{
			int val = it->first - 'a';
			visited[val]++;
			freq[val] = min(freq[val], it->second);
			it++;
		}
	}

	vector<string> res;

	for (int i = 0; i < 26; i++)
	{
		if (freq[i] != INT_MAX && visited[i] == words.size())
		{
			while (freq[i] > 0)
			{
				string s;
				s += i + 'a';
				res.push_back(s);
				freq[i]--;
			}
		}
	}

	return res;
}
};