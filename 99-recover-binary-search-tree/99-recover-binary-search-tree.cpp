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
        TreeNode* node1=NULL;
        TreeNode* node2=NULL;
        void solve(TreeNode* node,TreeNode* & pre){
                if(node->left){
                        solve(node->left,pre);
                }
                if(pre && pre->val>node->val){
                        if(node1==NULL){
                                node1=pre;
                        }
                        node2=node;
                }
                pre=node;
                if(node->right){
                        solve(node->right,pre);
                }
        }
    void recoverTree(TreeNode* root) {
            TreeNode * pre=NULL;
            solve(root,pre);
            swap(node1->val,node2->val);
            
        
    }
};