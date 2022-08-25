class Solution {
public:
    int countKDifference(vector<int>& ar, int k) {
        int ans =0 ;
        unordered_map<int,int> mymap;
        mymap[ar[0]]++;
        int n  =ar.size();
        for(int i = 1 ; i < n ;i++){
            int target1 = ar[i] + k;
            int target2 = ar[i] - k;
            if(mymap.count(target1)){
                ans += mymap[target1];
            }
            if(mymap.count(target2)){
                ans += mymap[target2];
            }
            mymap[ar[i]]++;
        }
      return ans;        
    }
};