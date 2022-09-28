class Solution {
public:
    

    int arraySign(vector<int>& nums) {
        int count_ve = 0;
        for(int i = 0 ; i < nums.size() ;i++){
            if(nums[i] < 0){
                count_ve++;
            }
            else if(nums[i] == 0){
                return 0;
            }
        }
        if(count_ve % 2 == 0){
            return 1;   
        }
        return -1;
    }
};