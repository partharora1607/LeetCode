class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& ar) {
        int n = ar.size();
        vector<int> ans;
        
        for(int i = 0 ; i < n ; i++){
            int idx = abs(ar[i]) - 1;
            if(ar[idx] > 0){
                ar[idx] *= -1;
            }
        }
        
        for(int i = 1; i <= n ; i++){
            if(ar[i - 1] > 0){
                ans.push_back(i);
            }
        }
        return ans;
        
        
    }
};