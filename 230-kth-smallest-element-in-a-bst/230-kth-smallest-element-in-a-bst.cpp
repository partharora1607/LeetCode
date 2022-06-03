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
vector<int> res;
void helper(TreeNode *root, int k)
{
    if (root == NULL) return;
    if(res.size() >= k) return;
    helper(root->left , k);
    res.push_back(root->val);
    helper(root->right , k);
}

int kthSmallest(TreeNode *root, int k)
{
    helper(root , k);
    return res[k - 1];
}
};