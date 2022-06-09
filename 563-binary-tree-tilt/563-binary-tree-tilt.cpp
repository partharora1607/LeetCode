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
    int sum = 0;
int helper(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftans = helper(root->left);
    int rightans = helper(root->right);
    int fans = leftans + rightans + root->val;
    root->val = abs(leftans - rightans);
    sum += root->val;
    return fans;
}

int findTilt(TreeNode *root)
{
    helper(root);
    return sum;
}
};