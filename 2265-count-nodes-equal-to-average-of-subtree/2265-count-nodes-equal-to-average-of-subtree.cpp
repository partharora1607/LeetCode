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

// no of nodes , sum
pair<int, int> *helpeR(TreeNode *root)
{
    if (root == NULL)
    {
        pair<int, int> *p1 = new pair<int, int>(0, 0);
        return p1;
    }

    pair<int, int> *leftans = helpeR(root->left);
    pair<int, int> *rightans = helpeR(root->right);

    pair<int, int> *ans = new pair<int, int>();

    ans->first = leftans->first + rightans->first + 1;
    ans->second = leftans->second + rightans->second + root->val;

    // check
    if ((ans->second / ans->first) == root->val)
    {
        res++;
    }

    return ans;
}

int averageOfSubtree(TreeNode *root)
{
    helpeR(root);
    return res;
}
};