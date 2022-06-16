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
int sum = 0;
int depth = 0;

void helper(TreeNode *root , int d){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        // leafnode;         
        if(d == depth){
            sum += root->val;
        }
       else if(d > depth){
            depth = d;
            sum = 0;
            sum += root->val;
        }
        return;
    }
    helper(root->right, d + 1);
    helper(root->left, d + 1);
}

int deepestLeavesSum(TreeNode *root)
{
    helper(root ,0);
    return sum;
}
};