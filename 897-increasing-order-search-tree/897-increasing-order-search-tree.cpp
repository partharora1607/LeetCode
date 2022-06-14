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
    // head, tail
pair<TreeNode *, TreeNode *> *helper(TreeNode *root)
{
    if (root == NULL)
    {
        pair<TreeNode *, TreeNode *> *p1 = new pair<TreeNode *, TreeNode *>(NULL, NULL);
        return p1;
    }
    TreeNode *fh = NULL;
    TreeNode *ft = NULL;
    pair<TreeNode *, TreeNode *> *leftans = helper(root->left);
    pair<TreeNode *, TreeNode *> *rightans = helper(root->right);

    pair<TreeNode *, TreeNode *> *ans = new pair<TreeNode *, TreeNode *>();
    root->left = NULL;
    if (leftans->first == NULL)
    {
        fh = root;
    }
    else
    {
        fh = leftans->first;
        leftans->second->right = root;
    }
    if (rightans->first == NULL)
    {
        ft = root;
    }
    else
    {
        root->right = rightans->first;
        ft = rightans->second;
    }
    ans->first = fh;
    ans->second = ft;
    return ans;
}

TreeNode *increasingBST(TreeNode *root)
{
    return helper(root)->first;
}
};