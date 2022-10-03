class Solution {
public:
    int search(vector<int>& ar, int target) {
        int si = 0 , ei =  ar.size() - 1;
        int mid;
        while(si <= ei){
            mid = (si + ei) / 2;
            if(ar[mid] == target){
                return mid;
            }
            else if(ar[mid] < target){
                si = mid + 1;
            }
            else{
                ei = mid - 1; 
            }
        }
        return -1;
    }
};