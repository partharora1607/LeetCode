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
        TreeNode *buildTree(vector<int> &inorder, int insi, int inei, vector<int> &postorder, int psi, int pei)
{
    if (insi > inei)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(postorder[pei]);
    int linsi = insi;
    int rinei = inei;
    int lpsi = psi;
    int rpei = pei - 1;
    int count = -1;
    for (int i = insi; i <= inei; i++)
    {
        if (inorder[i] == root->val)
        {
            count = i;
            break;
        }
    }
    int linei = count - 1;
    int rinsi = count + 1;
    int lpei = linei - linsi + lpsi;
    int rpsi = lpei + 1;
    root->left = buildTree(inorder, linsi, linei, postorder, lpsi, lpei);
    root->right = buildTree(inorder, rinsi, rinei, postorder, rpsi, rpei);
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}
};