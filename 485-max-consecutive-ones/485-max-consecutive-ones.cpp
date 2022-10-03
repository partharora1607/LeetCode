class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& ar) {
        ar.push_back(0);
        int n = ar.size();
        int count = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(ar[i] == 1){
                count++;
            }
            else
            {
                ans = max(ans , count);
                count = 0;
            }
        }
        return ans;
    }
};