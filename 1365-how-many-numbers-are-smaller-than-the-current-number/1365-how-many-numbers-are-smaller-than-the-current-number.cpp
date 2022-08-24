class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int> mymap;
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi , nums[i]);
            mymap[nums[i]]++;
        }
        
        vector<int> dp(101);
        dp[0] = 0;
        for(int i = 1 ; i < maxi + 1 ; i++){
            if(mymap.count(i - 1) == 0){
                dp[i] = dp[i - 1];
            }
            else{
                dp[i] = mymap[i - 1] + dp[i - 1];
            }
        }
        vector<int>ans;
        for(int i = 0 ; i < n ; i ++)
        {
            ans.push_back(dp[nums[i]]);
        }
        return ans;
        
    }
};