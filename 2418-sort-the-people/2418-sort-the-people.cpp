class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int , string , greater<int>> mymap;
        for(int i = 0 ; i <  heights.size(); i++){
            mymap[heights[i]] = names[i];
        }
        vector<string> ans;
        auto it = mymap.begin();
        while(it != mymap.end()){
            ans.push_back(it->second);
            it++;
        }
        return ans;
    }
};