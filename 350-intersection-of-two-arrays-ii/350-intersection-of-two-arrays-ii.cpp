class Solution {
public:
    vector<int> intersect(vector<int>& ar1, vector<int>& ar2) {
        unordered_map<int,int> mymap;
        int n = ar1.size();
        for(int i = 0 ; i  < n ; i++){
            mymap[ar1[i]]++;
        }
        
        vector<int> ans;
        
        for(int i = 0; i < ar2.size() ; i++){
            if(mymap.count(ar2[i]) && mymap[ar2[i]] >= 1){
                ans.push_back(ar2[i]);
                mymap[ar2[i]]--;
            }
        }
        return ans;
    }
};