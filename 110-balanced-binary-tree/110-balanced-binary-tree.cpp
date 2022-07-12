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
    // isbalanced , height
pair<bool, int> *helper(TreeNode *root)
{
    if (root == NULL)
    {
        pair<bool, int> *p1 = new pair<bool, int>(true, 0);
        return p1;
    }

    pair<bool, int> *leftans = helper(root->left);
    pair<bool, int> *rightans = helper(root->right);
    pair<bool, int> *ans = new pair<bool, int>();

    ans->first = (leftans->first && rightans->first) && (abs(leftans->second - rightans->second) <= 1);
    ans->second = max(leftans->second, rightans->second) + 1;
    return ans;
}

bool isBalanced(TreeNode *root)
{
    return helper(root)->first;
}
};