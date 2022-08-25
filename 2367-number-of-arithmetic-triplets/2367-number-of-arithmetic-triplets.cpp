class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        unordered_map<int,int> mymap;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mymap[nums[i]]++;
        }
        for(int i =0;i<n;i++){
            if(mymap.count(nums[i] - diff) && mymap.count(nums[i] + diff)){
                ans++;
            }
        }
        return ans;
    }
};