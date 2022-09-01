class Solution {
public:
    int distributeCandies(vector<int>& ar) {
        unordered_set<int> s1;
        int n = ar.size();
        int target = n / 2;
        for(int i = 0 ; i < n ;i++){
            s1.insert(ar[i]);
            if(s1.size() > target){
                return target;
            }
        }
        return s1.size();
        
        
    }
};