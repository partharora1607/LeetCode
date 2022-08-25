class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sum1 = nums[0] * nums[1];
        int sum2 = nums[n - 1] * nums[n - 2];
        return sum2 - sum1;
    }
};