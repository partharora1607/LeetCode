class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int count = 1;
        vector<int> ar;
        for(int i = 1 ; i < n ;i++){
            if (s[i] == s[i - 1]){
                count++;
            }
            else{
                ar.push_back(count);
                count = 1;
            }
        }
        ar.push_back(count);
        int ans = 0;
        for(int i = 1 ; i < ar.size() ;i++){
            ans += min(ar[i] , ar[i - 1]);
        }
        return ans;
    }
};