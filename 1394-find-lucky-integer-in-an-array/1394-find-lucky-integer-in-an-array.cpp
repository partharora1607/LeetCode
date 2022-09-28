class Solution {
public:
    int findLucky(vector<int>& ar) {
        unordered_map<int,int> mymap;
        for(int i = 0 ; i < ar.size() ;i++){
            mymap[ar[i]]++;
        }
        auto it = mymap.begin();
        int ans = -1;
        while(it != mymap.end()){
            if(it->second == it->first){
                ans = max(ans , it->first);
            }
            it++;
        }
        return ans;
    }
};