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
    // HEAD, TAIL
pair<TreeNode *, TreeNode *> *helper(TreeNode *root)
{
    if (root == NULL)
    {
        pair<TreeNode *, TreeNode *> *p1 = new pair<TreeNode *, TreeNode *>(NULL, NULL);
        return p1;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<TreeNode *, TreeNode *> *p1 = new pair<TreeNode *, TreeNode *>(root , root);
        return p1;
    }
    pair<TreeNode *, TreeNode *> *leftans = helper(root->left);
    pair<TreeNode *, TreeNode *> *rightans = helper(root->right);
    root->left = NULL;
    if (leftans->first != NULL && leftans->second != NULL)
    {
        root->right = leftans->first;
        leftans->second->right = rightans->first;
    }
    else root->right = rightans->first;
    pair<TreeNode *, TreeNode *> *ans = new pair<TreeNode *, TreeNode *>();
    ans->first = root;
    ans->second = rightans->second != NULL ? rightans->second : leftans->second;
    return ans;
}

void flatten(TreeNode *root)
{
    helper(root);
}
};