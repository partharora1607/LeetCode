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
    vector<TreeNode *> helper(int si, int ei)
{
    vector<TreeNode *> res;
    if (si > ei)
    {
        res.push_back(NULL);
        return res;
    }

    if (si == ei)
    {
        TreeNode *root = new TreeNode(si);
        res.push_back(root);
        return res;
    }

    // left ans                         rightans
    // 1     2                         4        5
    //  2  1                              5   4

    for (int i = si; i <= ei; i++)
    {
        // 1 2  3  4 5
        vector<TreeNode *> leftans = helper(si, i - 1);
        vector<TreeNode *> rigthans = helper(i + 1, ei);

        for (int j = 0; j < leftans.size(); j++)
        {
            for (int k = 0; k < rigthans.size(); k++)
            {
                TreeNode *root = new TreeNode(i);
                root->left = leftans[j];
                root->right = rigthans[k];
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode *> generateTrees(int n)
{
    return helper(1, n);
}
};