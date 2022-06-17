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

void getchildren(TreeNode *root)
{
    if(root == NULL){
        return;
    }
    if(root->left) sum += root->left->val;
    if(root->right) sum += root->right->val;
    return;
}

void helper(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->val % 2 == 0)
    {
        getchildren(root->left);
        getchildren(root->right);
    }
    helper(root->left);
    helper(root->right);
}

int sumEvenGrandparent(TreeNode *root)
{
    helper(root);
    return sum;
}
};