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
    
    void helper(TreeNode *root , int depth = 0)
    {       
        if(root == NULL){
            return;
        }
        if(res.size() > depth)
        {
            if(root->val > res[depth]){
                res[depth] = root->val;
            }   
        }
        else
        {
             res.push_back(root->val);
        }
        helper(root->left , depth + 1);
        helper(root->right , depth + 1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        helper(root);
        return res;
    }
};