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
    
int rob(TreeNode *root, map<pair<TreeNode *, bool>, int> &mymap, bool isParentLooted = false)
{
    if (root == NULL)
    {
        return 0;
    }
    if (mymap.count({root, isParentLooted}) > 0)
    {
        return mymap[{root, isParentLooted}];
    }
    int ans1 = 0;
    if (isParentLooted == false)
    {
        ans1 = rob(root->left, mymap, true) + rob(root->right, mymap, true) + root->val;
    }
    int ans2 = rob(root->left, mymap, false) + rob(root->right, mymap, false);
    mymap[{root, isParentLooted}] = max(ans1, ans2);
    return mymap[{root, isParentLooted}];
}

int rob(TreeNode *root)
{
    map<pair<TreeNode *, bool>, int> mymap;
    return rob(root, mymap);
}
};