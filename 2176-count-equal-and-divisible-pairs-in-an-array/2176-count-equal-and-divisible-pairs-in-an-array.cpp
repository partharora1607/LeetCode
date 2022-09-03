class Solution {
public:
    int countPairs(vector<int>& ar, int k) {
        unordered_map<int , vector<int>> mymap;
        int n = ar.size();
        for(int i =0 ; i < n ;i++){
            mymap[ar[i]].push_back(i);
        }
        
        int ans = 0;
        
        auto it = mymap.begin();
        while(it != mymap.end()){
            
            int n = it->second.size();
            if(n >= 2){
                for(int i =0 ; i < it->second.size() - 1;i++){
                    for(int j = i + 1 ; j < it->second.size() ; j++){
                        if((it->second[i] * it->second[j]) % k == 0){
                            ans++;        
                        }
                    }
                }
            }
            
            it++;
        }
        
        return ans;
    }
};