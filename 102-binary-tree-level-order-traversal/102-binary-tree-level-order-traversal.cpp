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
    map<int, vector<int>> mymap;

void helper(TreeNode *root, int level)
{
    if (!root)
        return;
    mymap[level].push_back(root->val);
    helper(root->left, level + 1);
    helper(root->right, level + 1);
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ar;
    helper(root, 0);
    map<int, vector<int>>::iterator it = mymap.begin();
    while (it != mymap.end())
    {
        ar.push_back(it->second);
        it++;
    }
    return ar;
}
};