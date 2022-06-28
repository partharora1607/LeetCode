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
    TreeNode *helper(vector<int> &ar, int si, int ei)
{
    if (si > ei) return NULL;
    if(si == ei){
        TreeNode *root = new TreeNode(ar[si]);
        return root;
    }
    TreeNode *root = new TreeNode(ar[si]);
    int index = 0;
    for (int i = si + 1; i <= ei; i++)
    {
        if (ar[i] > ar[si])
        {
            index = i;
            break;
        }
    }
    if(index == 0){
        index = ei + 1;
    }
    root->left = helper(ar, si + 1, index - 1);
    root->right = helper(ar, index, ei);
    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    return helper(preorder, 0, preorder.size() - 1);
}
};