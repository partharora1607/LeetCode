class Solution {
public:
    string destCity(vector<vector<string>>& v) {
        unordered_map<string , string> mymap;
        unordered_map<string , int> mp;
        for(int i = 0 ; i < v.size() ; i++){
            mp[v[i][1]]++;
            mymap[v[i][0]] = v[i][1];
        }
        string find;
        for(int i = 0 ; i < v.size() ; i++){
            if(mp.count(v[i][0]) == 0){
                find = v[i][0];
                break;
            }
        }
        while(mymap.count(find)){
            find = mymap[find];
        }
        return find;
    }
};