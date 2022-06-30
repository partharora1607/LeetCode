class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        
        vector<int> path;
        
        while(label>1){
            int level= floor(log2(label));
            path.push_back(label);
            int parent = (1<<(level+1))-label;    
            parent = (parent+1)/2 +(1<<level-1)-1;
            label= parent;
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
    
};