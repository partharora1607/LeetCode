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
vector<vector<int>> v;
vector<int> ans;
int sum = 0;

void helper(TreeNode *root, int target)
{
    if (root == NULL)
    {
        return;
    }

    sum += root->val;
    ans.push_back(root->val);

    if (root->left == NULL && root->right == NULL)
    {
        if (sum == target)
        {
            v.push_back(ans);
        }
        ans.pop_back();
        sum -= root->val;
        return;
    }

    helper(root->left, target);
    helper(root->right, target);
    sum -= root->val;
    ans.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    helper(root, targetSum);
    return v;
}
};