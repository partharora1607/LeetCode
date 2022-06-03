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

// Method - 1
int sumOfLeftLeaves(TreeNode *root, bool isleft = false)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return isleft ? root->val : 0;
    }
    return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
}
    
//     Method - 2
    
    
// int sum = 0;

// void helper(TreeNode *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
//     {
//         sum += root->left->val;
//     }

//     helper(root->left);
//     helper(root->right);
// }

// int sumOfLeftLeaves(TreeNode *root)
// {
//     helper(root);
//     return sum;
// }
    

};