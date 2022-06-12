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
int sum = INT_MIN;

int helper(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftans = max(helper(root->left), 0);
    int rightans = max(helper(root->right), 0);
    int ans = root->val + leftans + rightans;
    sum = max(sum, ans);
    return root->val + max(leftans, rightans);
}

int maxPathSum(TreeNode *root)
{
    helper(root);
    return sum;
}
};