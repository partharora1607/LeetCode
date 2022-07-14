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
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return root;
    if (root->val == key)
    {
        if (root->right && root->left)
        {
            TreeNode *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            temp->left = root->left;
            return root->right;
        }
        else if (root->right && root->left == NULL)
        {
            return root->right;
        }
        return root->left;
    }
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    return root;
}
};