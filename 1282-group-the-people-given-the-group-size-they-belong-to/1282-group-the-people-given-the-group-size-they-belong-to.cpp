class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& ar) {
        unordered_map<int , vector<int>> mymap;
        vector<vector<int>> res;
        for(int i =0 ; i < ar.size() ; i++){
            int size = ar[i];
            mymap[size].push_back(i);
            if(mymap[size].size() == size)
            {
                res.push_back(mymap[size]);
                mymap[size] = {};
            }
        }
        return res;
    }
};