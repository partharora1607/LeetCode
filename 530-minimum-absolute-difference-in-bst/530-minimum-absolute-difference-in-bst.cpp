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
    pair<int, pair<int, int>> *helper(TreeNode *root)
{
    if (root == NULL)
    {
        pair<int, pair<int, int>> *p1 = new pair<int, pair<int, int>>();
        p1->first = INT_MAX;
        p1->second.first = INT_MAX;
        p1->second.second = INT_MIN;
        return p1;
    }
    pair<int, pair<int, int>> *leftans = helper(root->left);
    pair<int, pair<int, int>> *rightans = helper(root->right);
    pair<int, pair<int, int>> *ans = new pair<int, pair<int, int>>();
    ans->second.first = min(root->val, min(leftans->second.first, rightans->second.first));
    ans->second.second = max(root->val, max(leftans->second.second, rightans->second.second));
    int ok = INT_MAX;
    if (root->left) ok = min(ok, abs(root->val - leftans->second.second));
    if (root->right) ok = min(ok, abs(root->val - rightans->second.first));
    int op2 = leftans->first;
    int op3 = rightans->first;
    ans->first = min(ok, min(op2, op3));
    return ans;
}

int getMinimumDifference(TreeNode *root)
{
    return helper(root)->first;
}
};