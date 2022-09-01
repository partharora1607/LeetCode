class Solution {
public:
    vector<int> sumZero(int n) {
            vector<int> ar(n);
            int i = 0 , j = n - 1;
            int target = n / 2;
            while(i <= j){
                ar[i++] = target * -1;
                ar[j--] = target;
                target--;
            }
        return ar;
    }
};