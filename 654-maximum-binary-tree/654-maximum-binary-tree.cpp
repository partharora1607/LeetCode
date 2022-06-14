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
    TreeNode *helper(vector<int> &ar, int si, int ei)
{
    if (si > ei)
    {
        return NULL;
    }
    int index = 0;
    int maxele = INT_MIN;
    for (int i = si; i <= ei; i++)
    {
        if (ar[i] > maxele)
        {
            maxele = ar[i];
            index = i;
        }
    }
    TreeNode *root = new TreeNode(maxele);
    root->left = helper(ar, si, index - 1);
    root->right = helper(ar, index + 1, ei);
    return root;
}

TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{
    return helper(nums, 0, nums.size() - 1);
}
};