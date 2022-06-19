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
   int ans = 0;

int helper(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftans = helper(root->left);
    int rightans = helper(root->right);

    int leftval = 0 , rightval = 0;

    if (root->left != NULL && root->left->val == root->val)
    {
        leftval += leftans + 1;
    }
    if (root->right != NULL && root->right->val == root->val)
    {
        rightval += rightans + 1;
    }
    ans = max(ans , leftval + rightval);
    return max(leftval , rightval);
}

int longestUnivaluePath(TreeNode *root)
{
    helper(root);
    return ans;
}
};