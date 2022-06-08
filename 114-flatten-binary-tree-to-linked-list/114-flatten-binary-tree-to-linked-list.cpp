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
class Solution {
private:
    TreeNode* recurse(TreeNode* root){
        if(!root) return nullptr;
        if(!(root->left) && !(root->right)) return root;
        if(!(root->left)) return recurse(root->right);
        
        if(!root->right){
            root->right = root->left;
            root->left = nullptr;
            TreeNode* last = recurse(root->right);
            return last;
        }
        
        TreeNode* right = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode* last = recurse(root->right);
        last->right = right;
        return recurse(right);
    }
public:
    void flatten(TreeNode* root) {
        recurse(root);
    }
};