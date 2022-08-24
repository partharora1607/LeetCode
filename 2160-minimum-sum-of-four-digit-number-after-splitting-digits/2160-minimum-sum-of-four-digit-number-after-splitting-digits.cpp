class Solution {
public:
    int minimumSum(int num) {
        vector<int> ar;
        while(num > 0){
            ar.push_back(num%10);
            num /= 10;
        }
        sort(ar.begin(),ar.end());
        int sum1 =0 , sum2 = 0;
        sum1 = ar[0]* 10;
        sum2 = ar[1] * 10;
        sum1 += ar[2];
        sum2 += ar[3];
        return sum1 + sum2;
    }
};