class Solution {
public:
    int findFinalValue(vector<int>& ar, int val) {
        unordered_map<int,int> mymap;
        for(int i = 0 ; i < ar.size(); i++){
            mymap[ar[i]]++;
        }
        
        while(mymap.count(val)){
            val*=2;
        }
        return val;
        
    }
};