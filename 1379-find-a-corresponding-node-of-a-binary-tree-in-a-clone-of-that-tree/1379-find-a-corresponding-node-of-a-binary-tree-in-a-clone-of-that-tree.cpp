/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
TreeNode *res;

bool helper(TreeNode *root , TreeNode *cloned , TreeNode *target){
    if(root == NULL){
        return false;
    }
    if(root == target){
        res = cloned;
        return true;
    }
    bool leftans = helper(root->left , cloned->left , target);
    if(leftans == true){
        return true;
    }
    bool rightans = helper(root->right , cloned->right , target);
    return rightans;
}

TreeNode *getTargetCopy(TreeNode *root, TreeNode *cloned, TreeNode *target)
{
    helper(root , cloned , target);
    return res;
}
};