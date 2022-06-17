class Solution {
public:
   void helper(vector<int> &ar ,int si , int ei){
       if(ei >= ar.size()){
           return;
       }
        int i = si , j = ei;
        while(i < j){
            swap(ar[i++] , ar[j--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        helper(nums , 0 , nums.size() - 1);
        helper(nums , 0 , k - 1);
        helper(nums , k , nums.size() - 1);
    }
};