class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<int> ans(s.length());
        for(int i = 0 ; i < indices.size() ;i++){
            ans[indices[i]] = s[i];
        }
        string ok;
        for(int i = 0; i < ans.size() ;i++){
            ok += ans[i];
        }
        return ok;
    }
};