class Solution {
public:
    int countElements(vector<int>& ar) {
        unordered_map<int,int> mymap;
        int n = ar.size();
        int mini = INT_MAX  , maxi = INT_MIN;
        for(int i = 0 ; i < n ; i ++){
            mymap[ar[i]]++;
            if(ar[i] < mini){
                mini = ar[i];
            }
            if(ar[i] > maxi){
                maxi = ar[i];
            }
        }
        
        
        // cout << maxi << "  " << mini << endl;
        int ans = 0;
        
        auto it = mymap.begin();
        while(it != mymap.end()){
            
            if(it->first != mini && it->first != maxi){
                ans += it->second;
            }
            it++;
        }
        
        return ans;
        
    }
};