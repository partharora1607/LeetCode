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
    bool helper(TreeNode *root, int limit, int sumsofar)
{
    if (root == NULL)
    {
        return true;
    }

    if (sumsofar + root->val < limit && root->left == NULL && !root->right)
    {
        return true;
    }
    if (sumsofar + root->val >= limit && !root->left && !root->right)
    {
        return false;
    }

    bool left = helper(root->left, limit, sumsofar + root->val);
    bool right = helper(root->right, limit, sumsofar + root->val);

    if (left)
    {
        root->left = NULL;
    }
    if(right){
        root->right = NULL;
    }
    return left && right;
}

TreeNode *sufficientSubset(TreeNode *root, int limit)
{
    if (!root)
        return NULL;
    bool ans = helper(root, limit, 0);
    if (ans)
        return NULL;
    return root;
}

};