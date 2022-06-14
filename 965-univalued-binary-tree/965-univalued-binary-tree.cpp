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
    bool isUnivalTree(TreeNode *root, int key)
{
    if(root == NULL){
        return true;
    }
    if(root->val != key){
        return false;
    }
    return isUnivalTree(root->left , key) && isUnivalTree(root->right , key);
}

bool isUnivalTree(TreeNode *root)
{
    return isUnivalTree(root, root->val);
}
};