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
    
int ans = 0;
int maxdepth = 0;

void helper(TreeNode *root, int depth = 0, bool isleft = false, bool isright = false)
{
    if(root == NULL){
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        if (depth > maxdepth)
        {
            maxdepth = depth;
            if (root->left)
            {
                ans = root->val;
            }
            else
            {
                ans = root->val;
            }
        }
        return;
    }
    helper(root->left, depth + 1, true, false);
    helper(root->right, depth + 1, false, true);
}

int findBottomLeftValue(TreeNode *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return root->val;
    }
    helper(root);
    return ans;
}
};