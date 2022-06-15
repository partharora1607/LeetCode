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
    string dfs(TreeNode *root, unordered_map<string, int> &m, vector<TreeNode *> &ans)
{
    if (root == NULL)
    {
        return "NULL";
    }
    string s = to_string(root->val) + ",";
    string a = dfs(root->left, m, ans) + "," ;
    string b = dfs(root->right, m, ans);
    s = s + a + b;
    if (m[s]++ == 1)
    {
        ans.push_back(root);
    }
    return s;
}

vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    unordered_map<string, int> m;
    vector<TreeNode *> ans;
    dfs(root, m, ans);
    return ans;
}
};