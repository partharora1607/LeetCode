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
    // toatl sum , replaced sum

pair<int, int> *helper(TreeNode *root)
{
    if (root == NULL)
    {
        pair<int, int> *p1 = new pair<int, int>(0, 0);
        return p1;
    }

    pair<int, int> *leftans = helper(root->left);
    pair<int, int> *rightans = helper(root->right);
    pair<int, int> *ans = new pair<int, int>();

    ans->first = root->val + leftans->first + rightans->first;
    root->val = abs(leftans->first - rightans->first);
    ans->second = leftans->second + rightans->second + root->val;
    return ans;
}

int findTilt(TreeNode *root)
{
    return helper(root)->second;
}
};