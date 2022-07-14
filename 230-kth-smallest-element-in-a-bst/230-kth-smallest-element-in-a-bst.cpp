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
    
int ans = -1;

// no of Nodes
int helper(TreeNode *root, int k)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftans = helper(root->left, k);
    k -= leftans;
    if (k == 0 && ans == -1)
    {
        ans = root->left->val;
    }
    k -= 1;
    if (k == 0 && ans == -1)
    {
        ans = root->val;
    }
    int rightans = helper(root->right, k);
    return leftans + rightans + 1;
}

int kthSmallest(TreeNode *root, int k)
{
    helper(root, k);
    return ans;
}
};