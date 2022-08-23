class Solution {
public:
    const int maxn=1e4+3;
    int deleteAndEarn(vector<int>& v) 
    {
        int n=v.size();
     map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[v[i]]++;
    }
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