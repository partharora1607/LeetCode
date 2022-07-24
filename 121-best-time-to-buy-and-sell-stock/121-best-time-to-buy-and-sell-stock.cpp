class Solution {
public:
int maxProfit(vector<int> &ar)
{
    int n = ar.size();

    if(n <= 1){
        return 0;
    }

    int L = 0;
    int R = 1;

    int ans = 0;

    while(R < n){
        while(R < n && ar[R] > ar[L]){
            ans = max(ans , ar[R] - ar[L]);
            R++;
        }
        L = R;
        R++;
    }

    return ans;
}
};