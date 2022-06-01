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
bool isbst(TreeNode *root, long long low, long long high)
{
    if (root == NULL)
        return true;

    if (root->val >= high || root->val <= low)
        return false;

    return isbst(root->left, low, root->val) && isbst(root->right, root->val, high);
}

bool isValidBST(TreeNode *root)
{
    return isbst(root, -2147483649, 2147483649); // when i passed ( INT_MIN - 1 ) , gives error so that i pass value
}
};