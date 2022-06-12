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
// maxsumpath(without split), root(split)

pair<int, int> *helper(TreeNode *root)
{
    if (root == NULL)
    {
        pair<int, int> *p1 = new pair<int, int>(INT_MIN, 0);
        return p1;
    }
    pair<int, int> *leftans = helper(root->left);
    pair<int, int> *rightans = helper(root->right);
    pair<int, int> *ans = new pair<int, int>();
    leftans->second = max((leftans->second), 0);
    rightans->second = max(rightans->second, 0);
    ans->second = root->val + max(leftans->second, rightans->second);
    int op1 = leftans->second + rightans->second + root->val;
    ans->first = max(leftans->first, max(rightans->first, op1));
    return ans;
}

int maxPathSum(TreeNode *root)
{
    return helper(root)->first;
}
};