class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> mpp;
        vector<vector<int>> ans;
        for(int i=0;i<groupSizes.size();i++)
        {
            mpp[groupSizes[i]].push_back(i);
        }
        for(auto it: mpp)
        {
            int check = (it.second.size()/it.first);
            vector<int> temp;
            // int i=0;
            while(check)
            {
                temp.push_back(it.second[0]);
                it.second.erase(it.second.begin());
                if(temp.size() == it.first)
                {
                    check--;
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ans;
    }
};