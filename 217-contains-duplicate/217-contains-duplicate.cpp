class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mymap;
        for(int i = 0 ; i < nums.size() ; i++){
            if(mymap.count(nums[i]) == 1){
                return true;
            }
            mymap[nums[i]]++;
        }
        return false;
    }
};