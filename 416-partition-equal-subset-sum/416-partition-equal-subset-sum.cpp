class Solution {
public:
    
    bool helper(vector<int> &nums , int si , int ei , int sum ,const int& target , vector<vector<int>> &output){
        if(si > ei){
            if(sum == target) return true;
            return false;
        }
        
        if(sum > target) return false;
        
        if(output[si][sum] != -1) return output[si][sum];
        
        return output[si][sum] = helper(nums , si + 1 , ei , sum , target , output) || helper(nums , si + 1 , ei , sum + nums[si] , target , output);
        
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto i:nums){
            sum += i;
        }
        if(sum % 2 != 0){
            return false;
        }
        vector<vector<int>> output(n , vector<int>(sum / 2 + 1 , -1));
        return helper(nums , 0 , n - 1 , 0 , sum / 2 , output);
    }
};