/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // root to node distance
vector<int> res;

void nodes_at_depth_k(TreeNode *root, int k , int level = 0)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == level)
    {
        res.push_back(root->val);
        return;
    }
    nodes_at_depth_k(root->left, k , level + 1);
    nodes_at_depth_k(root->right, k  , level + 1);
}

// distance from root to leaf
int helper(TreeNode *root, TreeNode *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->val == target->val)
    {
        nodes_at_depth_k(root, k);
        return 0;
    }

    int ld = helper(root->left, target, k);

    if (ld != -1)
    {
        if (ld + 1 == k)
        {
            res.push_back(root->val);
            return ld +1 ;
        }
            nodes_at_depth_k(root->right, k - ld - 2);
        return ld + 1;
    }

    int rd = helper(root->right, target, k);

    if (rd != -1)
    {
        if (rd + 1 == k)
        {
            res.push_back(root->val);
            return rd + 1;
        }
          nodes_at_depth_k(root->left, k - rd - 2);
        return rd + 1;
    }
    return -1;
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    helper(root, target, k);
    return res;
}
};