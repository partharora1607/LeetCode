class Solution {
public:
    vector<int> createTargetArray(vector<int> nums, vector<int> index) {
vector<int> v;
for(int i=0;i<nums.size();i++){
if(i>index[i]){
v.insert(v.begin()+index[i],nums[i]);
}
else{
v.push_back(nums[index[i]]);
}
}
return v;
}
};