class Solution {
public:
    int distributeCandies(vector<int>& ar) {
        unordered_set<int> s1;
        int n = ar.size();
        for(int i = 0 ; i < n ;i++){
            s1.insert(ar[i]);
        }
        int target = n / 2;
        if(s1.size() > target){
            return target;
        }
        return s1.size();
        
        
    }
};