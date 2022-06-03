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
vector<string> res;

string convert(int a)
{
    string s;
    for (int i = a; i != 0; i /= 10)
    {
        char c = (i % 10) + '0';
        s += c;
    }
    reverse(s.begin(), s.end());
    return s;
}

void helper(TreeNode *root, string s)
{
    if (root == NULL) return;
    if (root->val < 0) s += "-";
    s += convert(abs(root->val));
    if (root->left == NULL && root->right == NULL) res.push_back(s);
    s += "->";
    helper(root->left, s);
    helper(root->right, s);
}

vector<string> binaryTreePaths(TreeNode *root)
{
    string s = "";
    helper(root, s);
    return res;
}
};