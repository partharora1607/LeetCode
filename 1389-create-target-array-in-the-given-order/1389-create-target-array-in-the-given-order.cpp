class Solution {
public:
    vector<int> createTargetArray(vector<int>& ar, vector<int>& index) {
        vector<int> ans;
        for(int i = 0; i < ar.size() ; i++){
            ans.insert(ans.begin() + index[i],ar[i]);
        }
        return ans;
    }
};