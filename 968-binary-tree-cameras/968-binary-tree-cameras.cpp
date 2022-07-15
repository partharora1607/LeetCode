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
    

    
// 0 -> have camera
// 1-> vistited / covered
// -1 -> need camera

int ans = 0;

int helper(TreeNode *root )
{
    if(!root) return 1;
    if(!root->left && !root->right){
        return -1;// need camera
    }
    int leftans = helper(root->left);
    int rightans = helper(root->right);

    if(leftans == -1 || rightans == -1){
        ans++;
        return 0;
    }

    if(leftans == 0 || rightans == 0){
        return 1;
    }

    if(leftans == 1 && rightans == 1){
        return -1;
    }
    return 0;
}

int minCameraCover(TreeNode *root)
{
 int a = helper(root);
    if(a < 0){
        ans++;
    }
    return ans;
}
};