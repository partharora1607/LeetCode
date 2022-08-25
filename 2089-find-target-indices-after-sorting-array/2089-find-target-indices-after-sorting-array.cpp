class Solution {
public:
    vector<int> targetIndices(vector<int>& ar, int target) {
        unordered_map<int,int> mymap;
        for(int i =0 ; i < ar.size();i++){
            mymap[ar[i]]++;
        }
        if(mymap.count(target) == 0){
            return {};
        }
        int ans = 0;
        for(int i = 0 ; i < target ; i++){
            if(mymap.count(i) == 1){
                ans +=  mymap[i];
            }
            else{
                continue;
            }
        }
        vector<int> res;
        for(int i = 0 ; i < mymap[target] ;i++){
            res.push_back(ans + i);
        }
        return res;
    }
};