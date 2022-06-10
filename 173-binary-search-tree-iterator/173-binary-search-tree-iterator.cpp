/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private: stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    void pushAllLeft(TreeNode* root){
        while(root){
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        pushAllLeft(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
