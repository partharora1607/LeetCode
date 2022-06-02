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
    bool helper(TreeNode *root, int x, int sum)
{
    if (root == NULL)
    {
        return false;
    }
    sum += root->val;
    if (root->left == NULL && root->right == NULL)
    {
        if (sum == x)
        {
            return true;
        }
        return false;
    }

    bool leftans = helper(root->left, x, sum);
    if (leftans == true)
    {
        return true;
    }
    bool rightans = helper(root->right, x, sum);
    return rightans;
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    return helper(root, targetSum, 0);
}
};