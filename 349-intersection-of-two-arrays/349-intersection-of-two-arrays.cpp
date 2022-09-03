class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mymap;
        int n = nums1.size();
        for(int i = 0 ; i < n ; i++){
            mymap[nums1[i]]++;
        }
        vector<int> ans;
        for(int i = 0 ; i < nums2.size() ; i ++){
            if(mymap.count(nums2[i]) == 1){
                ans.push_back(nums2[i]);
                mymap.erase(nums2[i]);
            }
        }
        return ans;
    }
};