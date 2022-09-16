class Solution {
public:
    int thirdMax(vector<int>& ar) {
        unordered_map<int,int>mymap;
        int n = ar.size();
        for(int i = 0 ; i < n  ; i ++){
            mymap[ar[i]]++;
        }
        int  index =0 ;
        for(int i= 0 ; i < n; i ++){
            if(mymap.count(ar[i])){
                ar[index++] = ar[i];
                mymap.erase(ar[i]);
            }
        }
        
        for(int i = 0 ; i < index ; i++){
            cout << ar[i] << "  ";
        }
        
        
        
        n = index;
        
        cout <<  "n" << " " << n << endl;
        priority_queue<int , vector<int> , greater<int>> pq;
        for(int i =0; i < n && i < 3 ; i++){
            pq.push(ar[i]);
        }
        if(pq.size() < 3){
            cout << "hello" << endl;
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