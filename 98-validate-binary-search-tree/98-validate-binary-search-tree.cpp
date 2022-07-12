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
    bool inRange(TreeNode *root , long long minV , long long maxV){
    if(!root){return true;}
    if(root->val <= minV || root->val >= maxV){
        return false;
    }
    return inRange(root->left , minV , root->val) && inRange(root->right , root->val , maxV);
}

bool isValidBST(TreeNode *root)
{
    return inRange(root , -3000000000 , 3000000000);
}
};