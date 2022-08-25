class Solution {
public:
    int balancedStringSplit(string s) {
        int ans =0 ;
        int n= s.length();
        int lc =0  ,rc = 0;
        for(int i = 0;i<n;i++)
        {
            if(s[i] == 'R'){
                rc++;
            }
            else{
                lc++;
            }
            if(lc==rc){
                ans++;
            }
        }
        if(lc == rc){
            return ans;
        }
        return 0;
    }
};