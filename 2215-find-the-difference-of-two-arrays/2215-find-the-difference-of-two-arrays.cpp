class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mymap_1;
        unordered_map<int,int> mymap_2;
        for(int i = 0 ; i < nums1.size(); i++){
            mymap_1[nums1[i]]++;
        }
        for(int i = 0 ; i < nums2.size() ; i++){
            mymap_2[nums2[i]]++;
        }
        
        vector<int> ans1;
        vector<int> ans2;
        
        unordered_map<int , int> answala;
        
        for(int i = 0 ; i < nums1.size() ; i++)
        {
            if(mymap_2.count(nums1[i]) == 0 && answala.count(nums1[i]) == 0){
                ans1.push_back(nums1[i]);
                answala[nums1[i]]++;
            }
        }
        
        answala.clear();
        
        for(int i = 0 ; i < nums2.size() ; i++)
        {
            if(mymap_1.count(nums2[i]) == 0 && answala.count(nums2[i]) == 0){
                ans2.push_back(nums2[i]);
                answala[nums2[i]]++;
            }
        }
        
        return {ans1 , ans2};
        

    }
    
};