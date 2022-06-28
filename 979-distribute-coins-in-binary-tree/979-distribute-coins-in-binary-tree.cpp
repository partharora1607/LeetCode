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
    
int ans = 0;

int helper(TreeNode *root)
{
    if(root == NULL) return 0;
    int L = helper(root->left);
    int R = helper(root->right);
    ans += abs(L) + abs(R);
    return root->val + L + R - 1;
}

int distributeCoins(TreeNode *root)
{
    helper(root);
    return ans;
}

};