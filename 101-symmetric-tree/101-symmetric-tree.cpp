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
   bool isSymmetric(TreeNode *q, TreeNode *p)
{
    if(q == NULL && p == NULL){
        return true;
    }
    if(q == NULL || p == NULL){
        return false;
    }
    if(p->val != q->val){
        return false;
    }
    return isSymmetric(q->left , p->right) && isSymmetric(q->right , p->left);
}

bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }
    TreeNode *q = root->left;
    TreeNode *p = root->right;
    return isSymmetric(q, p);
}
};