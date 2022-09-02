class Solution {
public:
    int pivotIndex(vector<int>& ar) {
        int rightsum  = accumulate(ar.begin() , ar.end(), 0);
        int leftsum = 0;
        int n = ar.size();
        for(int i = 0 ; i < n ; i++){
            rightsum -= ar[i];
            if(leftsum == rightsum){
                return i;
            }
            leftsum += ar[i];
        }
        return -1;
    }
};