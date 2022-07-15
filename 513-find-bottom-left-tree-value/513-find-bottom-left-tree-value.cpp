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
    int max_depth = 0;
int res = 0;

// preorder Traversal
void helper(TreeNode *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if(root->left == NULL && root->right == NULL){
        if(level > max_depth){
            max_depth = level;
            res = root->val;
        }
        return;
    }

    helper(root->left , level + 1);
    helper(root->right , level + 1);


}

int findBottomLeftValue(TreeNode *root)
{
    if(root->left == NULL && root->right == NULL){
        return root->val;
    }
    helper(root , 0);
    return res;
}
};