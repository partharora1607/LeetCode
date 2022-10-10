class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int>target(n , -1);   
        for(int i = 0 ; i < n ; i++){
            int val = index[i];
            for(int j = n - 1; j > val; j--){
                target[j] = target[j - 1];
            }
            target[val] = nums[i];
        }
        return target;
    }
    
};