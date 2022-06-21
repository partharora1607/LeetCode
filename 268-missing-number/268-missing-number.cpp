class Solution {
public:
    
    int sum =0 ;
    
    void helper(vector<int> &nums){
        for(int i = 0 ; i < nums.size(); i++){
            sum += nums[i];
        }
    }
    
    int missingNumber(vector<int>& nums) {
        helper(nums);
        int n = nums.size();
        int val = n * (n + 1)/2;
        return val - sum;
    }
};