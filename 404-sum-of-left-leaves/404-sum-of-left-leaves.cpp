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
// is it a eaf node

int sum = 0;

bool helper(TreeNode *root){
    if(root == NULL){
        return false;
    }
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    bool leftans = helper(root->left);
    if(leftans){
        sum += root->left->val;
    }
    helper(root->right);
    return root->left == NULL && root->right == NULL;
}

int sumOfLeftLeaves(TreeNode *root)
{
    helper(root);
    return sum;
}
};