class Solution {
public:
    int minMovesToSeat(vector<int>& ar1, vector<int>& ar2) {
        sort(ar1.begin() , ar1.end());
        sort(ar2.begin() , ar2.end());
        
        int ans = 0;
        
        for(int i = 0 ; i < ar2.size() ; i++){
            ans += abs(ar1[i] - ar2[i]);
        }
        return ans;
        
    }
};