class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mymap;
        int n = nums.size();
        int target = n / 2;
        for(int i = 0 ; i  < n ; i++){
            mymap[nums[i]]++;
            if(mymap[nums[i]] == target){
                return nums[i];
            }
        }
        return -1;
    }
};