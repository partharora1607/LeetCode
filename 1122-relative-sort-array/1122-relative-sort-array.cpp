class Solution {
public:
    vector<int> relativeSortArray(vector<int>& ar1, vector<int>& ar2) {
        vector<int> ans;
        unordered_map<int,int>mymap;
        for(int i = 0 ; i < ar1.size() ; i ++){
            mymap[ar1[i]]++;
        }
        for(int i = 0 ; i < ar2.size() ; i++){
            while(mymap[ar2[i]] > 0){
                ans.push_back(ar2[i]);
                mymap[ar2[i]]--;
            }
            mymap.erase(ar2[i]);
        }
        vector<int> smallans;
        auto it = mymap.begin();
        while(it != mymap.end()){
            while(it->second > 0){
                smallans.push_back(it->first);
                it->second--;
            }
            it++;
        }
        sort(smallans.begin() , smallans.end());
        for(int i = 0 ; i < smallans.size() ; i++){
            ans.push_back(smallans[i]);
        }
        return ans;
    }
};