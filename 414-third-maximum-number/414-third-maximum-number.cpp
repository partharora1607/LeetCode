class Solution {
public:
    int thirdMax(vector<int>& ar) {
        unordered_map<int,int>mymap;
        int n = ar.size();
        int index = 0;
        for(int i = 0; i < n ;i++){
            if(mymap.count(ar[i]) == 0){
                ar[index++]=  ar[i];
            }
            mymap[ar[i]]++;
        }
                
        n = index;
        priority_queue<int , vector<int> , greater<int>> pq;
        for(int i =0; i < n && i < 3 ; i++){
            pq.push(ar[i]);
        }
        if(pq.size() < 3){
            while(pq.size() != 1){
                pq.pop();
            }
            return pq.top();
        }
        
        for(int i = 3 ; i < n ; i++){
            if(ar[i] > pq.top()){
                pq.pop();
                pq.push(ar[i]);
            }
            
        }
        return pq.top();
        
    }
};