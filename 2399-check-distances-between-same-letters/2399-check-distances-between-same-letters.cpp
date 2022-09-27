class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<int,int>mymap;
        int n = s.length();
        for(int i = 0 ; i < n ; i++)
        {
            if(mymap.count(s[i]) == 1)
            {
                int val = s[i] - 'a';
                int dis = abs(mymap[s[i]] - i) - 1;
                if(dis != distance[val])
                {
                    cout << dis << " " << distance[val] << endl;
                    return false;
                }
            }
            mymap[s[i]] = i;
        }
        return true;
    }
};