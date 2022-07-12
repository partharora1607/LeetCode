class Solution {
public:
int helper(int *ar, int n){
    if(n == 0 || n == 1){
        return 1;
    }
    if(ar[n] != -1){
        return ar[n];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {   
        ans += helper(ar , i - 1) * helper(ar , n - i);
    }
    ar[n] = ans;
    return ans;
}

int numTrees(int n){
    int *ar = new int[n + 1];
    for(int i = 0; i <= n ; i++){
        ar[i] = -1;
    }
    return helper(ar , n);
}
};