class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mymap;
        int n = nums2.size();
        for(int i = 0 ; i  < n ; i++){
            mymap[nums2[i]] = i;
        }
        
        vector<int> res;
        
        int n2 = nums1.size();
        for(int i = 0 ;  i < n2 ; i++){
            int j = mymap[nums1[i]] + 1;
            int ans = -1;
            for(;j < nums2.size() ; j++){
                if(nums2[j] > nums1[i]){
                    ans = nums2[j];
                    break;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};