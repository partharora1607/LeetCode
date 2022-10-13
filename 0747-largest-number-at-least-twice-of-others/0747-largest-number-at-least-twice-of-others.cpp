class Solution {
public:
    int dominantIndex(vector<int>& ar) {
        int l = INT_MIN,s = INT_MIN;
        int lidx = 0; 
        for(int i = 0 ; i< ar.size(); i++){
            if(ar[i] > l){
                s = l;
                l = ar[i];
                lidx = i;
            }
            else if(ar[i] > s && ar[i] <= l){
                s = ar[i];
            }
            else{
                continue;
            }
        }
        return (l >= 2 * s) ? lidx : -1;
    }
};