/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
TreeNode *helper(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == p->val || root->val == q->val)
    {
        return root;
    }
    if (root->val < p->val)
    {
        return helper(root->right, p, q);
    }
    if (root->val > q->val)
    {
        return helper(root->left, p, q);
    }
    if (root->val > p->val && root->val < q->val)
    {
        return root;
    }
    return NULL;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (p->val > q->val)
    {
        return helper(root, q, p);
    }
    return helper(root, p, q);
}
};