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
    // just trying to create height of tree  function
    int height(TreeNode *root)
    {
        if(!root)
            return 0;
        int left=height(root->left);
        int right=height(root->right);
        return max(left,right)+1;
    }
     void chalomatrixbanao(TreeNode* root, int l, int r, int h, vector<vector<string>>& ans) {
        if (root == NULL) return;
        if (l > r) return;
        int mid = (l + r) / 2;
        ans[h][mid] = to_string(root->val);
        chalomatrixbanao(root->left, l, mid-1, h+1, ans);
        chalomatrixbanao(root->right, mid+1, r, h+1, ans);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        // actually it is a simpke question of constructing tree from matrix 
      
        int h=height(root);
        int c=pow(2,h)-1;
        vector<vector<string>>res(h,vector<string>(c,""));
        chalomatrixbanao(root, 0, c-1, 0, res);
        return res;
        
        
        
    }
};