class Solution {
public:
    
    typedef pair<int, int> pi;
    
    vector<int> maxSubsequence(vector<int>& ar, int k) {
        if(ar.size() < k){
            return ar;
        }
        vector<int> res;
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        for(int i = 0 ; i < k ;i++){
            pq.push({ar[i] , i});
        }
        for(int i = k ; i < ar.size() ; i++){
            if(ar[i] > pq.top().first){
                pq.pop();
                pq.push({ar[i] , i});
            }
        }
        
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(res.begin() , res.end());
        for(int i = 0 ; i <  res.size() ; i++){
            res[i] = ar[res[i]];
        }
        return res;
        
        
    }
    
};