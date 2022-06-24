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
    vector<int> ans;
    int idx=0;
    bool solve(TreeNode* root, vector<int>& voyage){
        if(!root) return true;
        if(root->val != voyage[idx++]) return false;
        
        if(root->left && root->left->val!=voyage[idx]){
            ans.push_back(root->val);
            return solve(root->right,voyage) && solve(root->left,voyage);
        }
        
        return solve(root->left,voyage) && solve(root->right,voyage);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(solve(root,voyage)) return ans;
        else return {-1};
    }
};