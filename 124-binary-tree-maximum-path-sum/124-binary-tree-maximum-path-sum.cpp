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
    int helper(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftans = helper(root->left);
    int rightans = helper(root->right);
    leftans = max(leftans, 0);
    rightans = max(rightans, 0);
    return max(leftans , rightans) + root->val;
}

int maxPathSum(TreeNode *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }

    int leftans = maxPathSum(root->left);
    int rightans = maxPathSum(root->right);

    int op1 = max(helper(root->left), 0) + max(helper(root->right), 0) + root->val;

    return max(op1, max(leftans, rightans));
}
};