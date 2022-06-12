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
    
int helper(TreeNode *root, long long int currsum, int targetsum)
{
    if (root == NULL)
    {
        return 0;
    }
    currsum += root->val;
    if (currsum == targetsum)
    {
        return helper(root->left, currsum, targetsum) + helper(root->right, currsum, targetsum) + 1;
    }
    return helper(root->left, currsum, targetsum) + helper(root->right, currsum, targetsum);
}

int pathSum(TreeNode *root, int targetSum)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans1 = helper(root, 0, targetSum);
    int leftans = pathSum(root->left, targetSum);
    int rightans = pathSum(root->right, targetSum);
    return ans1 + leftans + rightans;
}
};