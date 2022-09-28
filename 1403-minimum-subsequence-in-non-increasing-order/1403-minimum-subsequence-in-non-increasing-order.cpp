class Solution {
public:
    vector<int> minSubsequence(vector<int>& ar) 
    {
        sort(ar.begin() , ar.end());
        int sum = accumulate(ar.begin() , ar.end() , 0);
        
        int n = ar.size();
        int curr_sum = 0;
        
        vector<int> ans; 
        
        for(int i = n - 1;i >= 0 ; i--){
            curr_sum += ar[i];
            sum -= ar[i];
            
            ans.push_back(ar[i]);
            if(curr_sum > sum){
                return ans;
            }
            
        }
        return ans;
    }
};