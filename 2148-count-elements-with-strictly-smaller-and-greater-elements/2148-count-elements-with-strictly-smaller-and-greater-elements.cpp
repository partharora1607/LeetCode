class Solution {
public:
    int countElements(vector<int>& ar) {
        unordered_map<int,int> mymap;
        int n = ar.size();
        
        if(n <= 2){
            return 0;
        }
        
        int mini = INT_MAX  , maxi = INT_MIN;
        for(int i = 0 ; i < n ; i ++){
            mymap[ar[i]]++;
            if(ar[i] < mini){
                mini = ar[i];
            }
            if(ar[i] > maxi){
                maxi = ar[i];
            }
        }
        
        
        // cout << maxi << "  " << mini << endl;
        int ans = 0;
        
        ans = n - mymap[mini] - mymap[maxi];
        
        return ans > 0 ? ans : 0;
        
    }
};