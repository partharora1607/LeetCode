class Solution {
public:
    int maxProfit(vector<int>& ar) {
        int n = ar.size();
        
        if(n <= 1)
        {
            return  0;
        }
        
        vector<int> leftans(n);// sell constraint
        vector<int> rightans(n); // buy constraint
        
        leftans[0] = 0;
        
        int ans = 0;
        
        int min_so_far= ar[0];
        
        for(int i = 1 ; i < n ; i++){
            leftans[i] = max(ans , ar[i] - min_so_far);
            min_so_far = min(min_so_far , ar[i]);
            ans = max(ans , leftans[i]);
        }
        
        int max_so_far = ar[n - 1];
        rightans[n - 1] = 0;
        ans = 0;
        
        for(int j = n - 2 ; j >= 0 ;j --){
            rightans[j] = max(ans , max_so_far - ar[j]);
            max_so_far = max(max_so_far , ar[j]);
            ans =  max(ans ,rightans[j]);
        }
        
        ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            ans = max(ans , leftans[i] + rightans[i]);
        }
        
        return ans;
        
        
    }
};