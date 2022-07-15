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
vector<TreeNode *> res;
unordered_map<string, int> mymap;

string dfs(TreeNode *root)
{
    if (root == NULL)
    {
        return "NULL";
    }
    string s = to_string(root->val);
    s += ',';
    string a = dfs(root->left);
    a += ',';
    string b = dfs(root->right);
    s = s + a + b;
    mymap[s]++;
    if(mymap[s] == 2){
        res.push_back(root);
    }
    return s;   
}

vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    dfs(root);
    return res;
}
};