class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& ar) {
        vector<vector<int>> res;
        unordered_map<int , vector<int>> mymap;
        for(int i = 0; i < ar.size();i++){
            mymap[ar[i]].push_back(i);
            if(mymap[ar[i]].size() == ar[i]){
                res.push_back(mymap[ar[i]]);
                mymap[ar[i]]={};
            }
        }
        return res;
    }
};