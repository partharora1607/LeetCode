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
    
int depth(TreeNode *root, int val)
{
    if(root == NULL){
        return -1;
    }
    if(root->val == val){
        return 0;
    }
    int leftans = depth(root->left , val);
    if(leftans != -1){
        return leftans + 1;
    }
    int rightans = depth(root->right , val);
    if(rightans != -1){
        return rightans + 1;
    }
    return -1;
    
}

bool areBrothers(TreeNode *root, int x, int y)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->left && root->right)
    {
        if ((root->left->val == x && root->right->val == y) || (root->left->val == y && root->right->val == x))
        {
            return true;
        }
    }
    return areBrothers(root->left, x, y) || areBrothers(root->right, x, y);
}

bool isCousins(TreeNode *root, int x, int y)
{
    return depth(root, x) == depth(root, y) && !areBrothers(root, x, y);
}
};