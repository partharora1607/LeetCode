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
// node , hasone(flag)

pair<TreeNode *, bool> *helper(TreeNode *root)
{
    if (root == NULL)
    {
        pair<TreeNode *, bool> *p1 = new pair<TreeNode *, bool>(NULL, false);
        return p1;
    }

    pair<TreeNode *, bool> *leftans = helper(root->left);
    pair<TreeNode *, bool> *rightans = helper(root->right);
    
    root->left = leftans->first;
    root->right = rightans->first;

    if (root->val == 1)
    {
        pair<TreeNode *, bool> *p1 = new pair<TreeNode *, bool>(root, true);
        return p1;
    }

    pair<TreeNode *, bool> *ans = new pair<TreeNode *, bool>();
    if (leftans->second == false && rightans->second == false && root->val == 0)
    {
        ans->first = NULL;
        ans->second = false;
    }
    else
    {
        ans->first = root;
        ans->second = true;
    }
    return ans;
}

TreeNode *pruneTree(TreeNode *root)
{
    return helper(root)->first;
}
};