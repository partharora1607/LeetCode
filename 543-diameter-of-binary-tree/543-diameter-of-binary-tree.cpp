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
    // height , diameter
pair<int, int> *helper(TreeNode *root)
{
    // base case
    if (root == NULL)
    {
        pair<int, int> *p1 = new pair<int, int>(0, 0);
        return p1;
    }
    pair<int, int> *leftans = helper(root->left);
    pair<int, int> *rightans = helper(root->right);
    pair<int, int> *ans = new pair<int, int>();
    ans->first = max(leftans->first, rightans->first) + 1;
    ans->second = max(leftans->second, max(rightans->second, leftans->first + rightans->first));
    return ans;
}

int diameterOfBinaryTree(TreeNode *root)
{
    return helper(root)->second;
}
};