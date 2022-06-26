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
int res = 0;
// leftans , rightans
pair<int, int> *helper(TreeNode *root)
{
    if (root == NULL)
    {
        pair<int, int> *p1 = new pair<int, int>(-1, -1);
        return p1;
    }

    if (root->left == NULL && root->right == NULL)
    {
        pair<int, int> *p1 = new pair<int, int>(0, 0);
        return p1;
    }

    pair<int, int> *leftans = helper(root->left);
    pair<int, int> *rightans = helper(root->right);

    pair<int, int> *ans = new pair<int, int>();

    // ans -> leftans
    ans->first = leftans->second + 1;
    ans->second = rightans->first + 1;

    res = max(res, max(ans->first, ans->second));
    return ans;
}

int longestZigZag(TreeNode *root)
{
    helper(root);
    return res;
}
};