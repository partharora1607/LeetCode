class Solution {
public:
    int mostFrequent(vector<int>& ar, int target) {
        unordered_map<int,int> mymap;
        int n = ar.size();
        int freq = 0 , ans = 0;
        for(int i = 0 ; i < n  - 1 ;i++){
            if(ar[i]== target){
                mymap[ar[i + 1]]++;
            }
            if(mymap[ar[i + 1]] > freq){
                freq = mymap[ar[i + 1]];
                ans = ar[i + 1];
            }        
        }
        return ans;
    }
};