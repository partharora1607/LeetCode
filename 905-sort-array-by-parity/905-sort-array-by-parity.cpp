class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& ar) {
        int n = ar.size();
        int i = 0 , j = n - 1;
        while(i < j)
        {
            if(ar[i] % 2 == 0){
                i++;          
            }
            else if(ar[j] % 2 != 0){
                j--;
            }
            else{
                swap(ar[i], ar[j]);
            }
        }
        return ar;
    }
    
};