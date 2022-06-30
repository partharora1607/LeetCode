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
public:
    
    bool helper(TreeNode *root , int target){
        if(root == NULL)
        {
            return true;
        }
        if(root->left == NULL && root->right == NULL)
        {
            if(root->val == target){
                return true;
            }    
            return false;
        }
        bool leftans = helper(root->left , target);
        bool rightans = helper(root->right , target);
        
        if(leftans){
            root->left = NULL;
        }
        if(rightans){
            root->right = NULL;
        }
        if(leftans && rightans && root->val == target){
            return true;
        }
        return false;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) 
    {
        if(!root) return NULL;
       bool ans = helper(root , target);
        if(ans == true){
            return NULL;
        }
        return root;
    }
};