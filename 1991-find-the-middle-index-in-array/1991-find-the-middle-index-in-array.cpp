class Solution {
public:
    int findMiddleIndex(vector<int>& ar) {
        int n = ar.size();
        if(n == 1){
            return 0;
        }
        int totalsum = accumulate(ar.begin() , ar.end(),0);
        int leftsum =0  , rightsum = 0;
        if(totalsum - ar[0] == 0){
            return 0;
        }
        for(int i = 1 ; i < n ; i ++){
            leftsum += ar[i - 1];
            rightsum = totalsum - leftsum - ar[i];
            if(leftsum == rightsum){
                return i;
            }
        }
        return -1;
    }
};