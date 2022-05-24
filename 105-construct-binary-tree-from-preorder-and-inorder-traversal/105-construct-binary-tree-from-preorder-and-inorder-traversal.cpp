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
    TreeNode *buildTree(vector<int> &preorder, int psi, int pei, vector<int> &inorder, int isi, int iei)
{
    if (psi > pei)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(preorder[psi]);
    int lpsi = psi + 1;
    int rpei = pei;
    int lisi = isi;
    int riei = iei;

    int count = -1;
    for (int i = isi; i <= iei; i++)
    {
        if (inorder[i] == root->val)
        {
            count = i;
            break;
        }
    }

    int liei = count - 1;
    int risi = count + 1;

    int lpei = lpsi + liei - lisi;
    int rpsi = lpei + 1;

    root->left = buildTree(preorder, lpsi, lpei, inorder, lisi, liei);
    root->right = buildTree(preorder, rpsi, rpei, inorder, risi, riei);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}
};