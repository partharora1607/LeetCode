class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int j = 1;
        int n = nums.size();
        for(int i = 0; i < n ; i+=2){// even
            if(nums[i] % 2 != 0){
                while(nums[i] % 2 != 0){
                    swap(nums[i] , nums[j]);
                    j+=2;
                }
            }
        }
        return nums;
    }
};