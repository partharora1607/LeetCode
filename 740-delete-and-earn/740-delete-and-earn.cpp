class Solution {
public:
    int deleteAndEarn(vector<int>& v) 
    {
        int maxn = pow(10,4) + 1;
        int n=v.size();
    vector<int> freq(maxn,0);
    
    for(int i=0;i<n;i++){
        freq[v[i]]++;
    }    
    vector<int> dp(maxn,0);
    dp[0]=0;
    dp[1]=freq[1];
    for(int i=2;i<maxn;i++){
        dp[i]=max(dp[i-2]+i*freq[i],dp[i-1]);
    }
        return dp.back();
                                   
    }
};