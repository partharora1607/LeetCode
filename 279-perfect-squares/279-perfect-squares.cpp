class Solution {
public:
    int numSquares(int n)
{
    if(n <= 3){
        return n;
    }
    vector<int> output(n + 1);

    output[0] = 0;
    output[1] = 1;
    output[2] = 2;
    output[3] = 3;

    for (int i = 4; i <= n; i++)
    {   
        int j = 1;
        int ans = pow(10,7);
        while(j * j <= i){
            int smallans = output[i - (j * j)] + 1;
            ans = min(ans , smallans);
            j++;
        }
        output[i] = ans;
    }
    return output[n];

}
};