class Solution {
public:
    int findNumbers(vector<int>& ar) {
        int  n = ar.size();
        int count =0 ;
        for(int i = 0 ; i < n ; i ++){
            string s = to_string(ar[i]);
            int size = s.size();
            if(size % 2 == 0){
                count++;
            }
        }
        return count;
    }
};