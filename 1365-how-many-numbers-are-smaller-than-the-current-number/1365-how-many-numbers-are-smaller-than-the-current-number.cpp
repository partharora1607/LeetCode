class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int> mymap;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            mymap[nums[i]]++;
        }
        
        vector<int> dp(101);
        dp[0] = 0;
        for(int i = 1 ; i < 101 ; i++){
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