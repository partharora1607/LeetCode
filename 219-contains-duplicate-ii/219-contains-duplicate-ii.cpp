class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& ar, int k) {
        unordered_map<int,int> mymap;
        int n = ar.size();
        for(int i = 0 ; i< n ; i++){
            if(mymap.count(ar[i]) != 0){
                if(abs(i - mymap[ar[i]]) <= k){
                    return true;
                }
            }
            mymap[ar[i]] = i;
        }
        return false;
    }
};