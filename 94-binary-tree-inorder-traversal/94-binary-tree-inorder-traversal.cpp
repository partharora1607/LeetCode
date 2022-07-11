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
    vector<int> inorderTraversal(TreeNode *root)
{
    if (!root) return {};

    vector<int> leftside;
    vector<int> rightside;

    vector<int> res;

    leftside = inorderTraversal(root->left);
    rightside = inorderTraversal(root->right);

    res = leftside;
    res.push_back(root->val);
    for (int i = 0; i < rightside.size(); i++)
    {
        res.push_back(rightside[i]);
    }
    return res;
}
};