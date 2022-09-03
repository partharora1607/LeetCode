class Solution {
public:
    vector<int> intersection(vector<vector<int>>& v) {
        int n = v.size();
        unordered_map<int,int> mymap;
        for(int i = 0; i < v.size() ;i++){
            for(int j =0 ; j < v[i].size() ;j++){
                mymap[v[i][j]]++;
            }
        }
        vector<int> res;
        auto it = mymap.begin();
        while(it != mymap.end()){
            if(it->second == n){
                res.push_back(it->first);
            }
            it++;
        }
        sort(res.begin() , res.end());
        return res;
    }
};