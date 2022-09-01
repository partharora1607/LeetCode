class Solution {
public:
    vector<int> numberOfPairs(vector<int>& ar) {
        vector<int> ans;
        int count_pair = 0;
        int leftpair = 0;
        
        int n = ar.size();
        
        unordered_map<int,int> mymap;
        for(int i = 0 ; i < n ; i++){
            mymap[ar[i]]++;
        }
        
        auto it = mymap.begin();
        while(it != mymap.end()){
            count_pair += (it->second) / 2;
            leftpair += (it->second) % 2;
            it++;
        }
        
        ans.push_back(count_pair);
        ans.push_back(leftpair);
        return ans;
        
    }
};