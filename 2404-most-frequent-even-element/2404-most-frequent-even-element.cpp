class Solution {
public:
    int mostFrequentEven(vector<int>& ar) {
        int freq = 0;
        int ans = -1;
        int n = ar.size();
        unordered_map<int,int>mymap;
        for(int i = 0 ; i < n ; i++){
            if(ar[i]% 2 == 0){
                mymap[ar[i]]++;
            }
        }
        auto it = mymap.begin();
        
        while(it != mymap.end()){
                if(it->second > freq){
                freq = it->second;
                ans = it->first;
            }
            else if(it->second == freq){
                ans = min(ans , it->first);
            }
            it++;
        }
            
        return ans;
    }
};