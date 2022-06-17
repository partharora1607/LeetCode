class Solution {
public:
   void helper(vector<int> &ar ,int si , int ei){
        while(si < ei){
            swap(ar[si++] , ar[ei--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        helper(nums , 0 , nums.size() - 1);
        helper(nums , 0 , k - 1);
        helper(nums , k , nums.size() - 1);
    }
};