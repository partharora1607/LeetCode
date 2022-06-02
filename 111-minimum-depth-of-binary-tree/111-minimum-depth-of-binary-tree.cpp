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
int minDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        return 1;
    }
    int leftans = INT_MAX;
    if (root->left)
    {
        leftans = minDepth(root->left);
    }
    int rightans = INT_MAX;
    if (root->right)
    {
        rightans = minDepth(root->right);
    }
    return min(rightans, leftans) + 1;
}
};