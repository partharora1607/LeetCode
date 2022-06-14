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
    int res = INT_MAX;

// min , max
pair<int, int> *helper(TreeNode *root)
{
    if (root == NULL)
    {
        pair<int, int> *p1 = new pair<int, int>(100000, -100000);
        return p1;
    }

    pair<int, int> *leftans = helper(root->left);
    pair<int, int> *rightans = helper(root->right);
    pair<int, int> *ans = new pair<int, int>();

    res = min(res, abs(root->val - leftans->second));
    res = min(res, abs(root->val - rightans->first));

    ans->first = min(root->val, min(leftans->first, rightans->first));
    ans->second = max(root->val, max(leftans->second, rightans->second));
    return ans;
}

int minDiffInBST(TreeNode *root)
{
    helper(root);
    return res;
}
};