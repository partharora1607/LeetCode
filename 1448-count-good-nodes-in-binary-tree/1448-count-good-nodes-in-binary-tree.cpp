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
int count = 0;

void helper(TreeNode *root , int max_so_far){
    if(!root) return;
    if(root->val >= max_so_far){
        count++;
    }
    max_so_far = max(max_so_far , root->val);
    helper(root->left , max_so_far);
    helper(root->right , max_so_far);
}

int goodNodes(TreeNode *root)
{
    helper(root ,INT_MIN);
    return count;
}
};