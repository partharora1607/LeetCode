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
// head, tail
pair<TreeNode *, TreeNode *> *helper(TreeNode *root)
{
    if (!root)
        return new pair<TreeNode *, TreeNode *>(NULL, NULL);
    if (!root->left && !root->right)
        return new pair<TreeNode *, TreeNode *>(root, root);

    pair<TreeNode *, TreeNode *> *leftans = helper(root->left);
    pair<TreeNode *, TreeNode *> *rightans = helper(root->right);

    pair<TreeNode *, TreeNode *> *ans = new pair<TreeNode *, TreeNode *>();

    root->left = NULL;

    ans->first = root;
    if (leftans->first == NULL)
    {
        root->right = rightans->first;
        ans->second = rightans->second;
        return ans;
    }
    else
    {
        root->right = leftans->first;
        leftans->second->right = rightans->first;
        if (rightans->first != NULL)
        {
            ans->second = rightans->second;
        }
        else
        {
            ans->second = leftans->second;
        }
    }
    return ans;
}

void flatten(TreeNode *root)
{
    helper(root);
}
};