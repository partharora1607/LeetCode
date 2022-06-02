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

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == NULL)
    {
        return false;
    }

    sum += root->val;

    if (root->left == NULL && root->right == NULL)
    {
        if (sum == targetSum)
        {
            return true;
        }
        sum -= root->val;
        return false;
    }

    bool leftans = hasPathSum(root->left, targetSum);
    if (leftans)
    {
        return true;
    }
    bool rightans = hasPathSum(root->right, targetSum);
    if (rightans)
    {
        return true;
    }
    sum -= root->val;
    return false;
}
};