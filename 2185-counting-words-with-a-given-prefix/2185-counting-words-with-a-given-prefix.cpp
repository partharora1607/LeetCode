class Solution {
public:
    int prefixCount(vector<string>& v, string pref) {
        int n = pref.size();
        int ans =0 ;
        for(int i = 0 ; i < v.size() ; i++){
            string s1 = v[i];
            if(s1.substr(0, n) == pref){
                ans++;
            }
        }
        return ans;
    }
};