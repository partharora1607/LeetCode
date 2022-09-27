class Solution {
public:
    int countPrefixes(vector<string>& v, string s) {
        int ans = 0;
        for(int i = 0 ; i < v.size() ; i++){
            string s1 = v[i];
            if(s1.size() > s.size()){
                continue;
            }
            else{
                if(s1 == s.substr(0 , s1.size())){
                    ans++;
                }
            }
        }
        return ans;
    }
};