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
    int preInd = 0, postInd = 0;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode *root = new TreeNode(pre[preInd++]);
        if(root->val != post[postInd]) {
            root->left = constructFromPrePost(pre, post);
        }
        if(root->val != post[postInd]) {
            root->right = constructFromPrePost(pre, post);
        }
        postInd++;
        return root;
    }
};