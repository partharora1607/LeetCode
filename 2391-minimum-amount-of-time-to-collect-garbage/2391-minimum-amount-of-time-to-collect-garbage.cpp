class Solution {
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
{
    int g = 0, p = 0, m = 0;
    int gc = 0, pc = 0, mc = 0;
    for (int i = 0; i < garbage.size(); i++)
    {
        string s = garbage[i];
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == 'G')
            {
                g = i;
                gc++;
            }
            else if (s[j] == 'P')
            {
                p = i;
                pc++;
            }
            else
            {
                m = i;
                mc++;
            }
        }
    }

    int ans = gc + pc + mc;
        
    for (int i = 0; i < g; i++)
    {
        ans += travel[i];
    }
    for (int i = 0; i < p; i++)
    {
        ans += travel[i];
    }
    for (int i = 0; i < m; i++)
    {
        ans += travel[i];
    }
    return ans;
}
};