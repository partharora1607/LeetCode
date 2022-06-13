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
    TreeNode *helper(TreeNode *root, int val, int depth, int curr_depth)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (depth - curr_depth == 1)
    {
        TreeNode *leftside = root->left;
        TreeNode *rightside = root->right;
        TreeNode *l = new TreeNode(val);
        TreeNode *r = new TreeNode(val);
        root->left = l;
        root->right = r;
        l->left = leftside;
        r->right = rightside;
        return root;
    }
    root->left = helper(root->left, val, depth, curr_depth + 1);
    root->right = helper(root->right, val, depth, curr_depth + 1);
    return root;
}

TreeNode *addOneRow(TreeNode *root, int val, int depth)
{
    if (depth == 1)
    {
        TreeNode *newroot = new TreeNode(val);
        newroot->left = root;
        return newroot;
    }
    return helper(root, val, depth, 1);
}

};