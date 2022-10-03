class Solution {
public:
    int binary(vector<int>&nums, int low, int high ,int target){
    
    if(low>high) return -1;
  
    int mid=low+(high-low)/2;
    
    if(nums[mid]==target) return mid;
    
    if(nums[mid]<target)
        return binary(nums,mid+1,high,target);   
    
    
    else
        return binary(nums,low,mid-1,target);
    
} 

int search(vector<int>& nums, int target) {
    
    int start = 0;
    int end = nums.size()-1;
    return binary(nums,start,end,target);
	}

};