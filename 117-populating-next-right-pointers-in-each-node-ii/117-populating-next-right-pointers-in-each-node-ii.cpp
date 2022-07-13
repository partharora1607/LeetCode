/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
       // int -> level / depth , vector<int> -> nodes at that level
unordered_map<int, vector<Node *>> mymap;

void dfs(Node *root , int level){
    if(!root) return;
    if(mymap[level].size() == 0){
        // vector is empty
        mymap[level].push_back(root);
    }
   else if(mymap[level].size() >= 1){
        int n = mymap[level].size(); 
        root->next = mymap[level][n - 1];
        mymap[level].push_back(root);
    }
    dfs(root->right , level + 1);
    dfs(root->left , level + 1);
}

Node *connect(Node *root)
{
    dfs(root , 0);
    return root;
}
};  