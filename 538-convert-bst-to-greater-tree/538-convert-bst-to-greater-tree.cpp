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
int currsum = 0;
int helper(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int rightans = helper(root->right);
    currsum += root->val;
    int store = root->val;
    root->val = currsum;
    int leftans = helper(root->left);
    return leftans + rightans + store;
}
TreeNode *convertBST(TreeNode *root)
{
    helper(root);
    return root;
}
};