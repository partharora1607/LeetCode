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
    int rob(TreeNode *root, bool isparent_looted, map<pair<TreeNode *, bool>, int> &mymap)
{
    if (root == NULL)
    {
        return 0;
    }

    if (mymap.count({root, isparent_looted}) == 1)
    {
        return mymap[{root, isparent_looted}];
    }

    int op1 = INT_MIN, op2 = INT_MIN;

    if (isparent_looted == true)
    {
        int leftans = rob(root->left, false , mymap);
        int rightans = rob(root->right, false , mymap);
        op1 = leftans + rightans;
    }
    else
    {
        op1 = rob(root->left, false , mymap) + rob(root->right, false , mymap);
        op2 = root->val + rob(root->left, true , mymap) + rob(root->right, true , mymap);
    }
    mymap[{root, isparent_looted}] = max(op1, op2);
    return max(op1, op2);
}

int rob(TreeNode *root)
{
    map<pair<TreeNode * , bool> , int> mymap;
    return rob(root , false , mymap);
}
};