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
int sumNumbers(TreeNode *u, int s = 0)
{
    if (!u) return 0;
    s = s * 10 + u->val;
    if (!u->left  && !u->right) return s;
    return sumNumbers(u->left, s) + sumNumbers(u->right, s);
}
};