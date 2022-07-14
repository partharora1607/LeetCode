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
    vector<int> res;

int precurssor = INT_MIN;
int currfreq = 0;
int max_freq = 0;

void helper(TreeNode *root)
{
    if (root == NULL)
        return;
    helper(root->left);
    if (precurssor == root->val)
    {
        currfreq += 1;
    }
    else
    {
        currfreq = 1;
    }
    if (currfreq > max_freq)
    {
        res.clear();
        max_freq = currfreq;
        res.push_back(root->val);
    }
    else if(currfreq == max_freq)
    {
        res.push_back(root->val);
    }
    precurssor = root->val;
    helper(root->right);
}

vector<int> findMode(TreeNode *root)
{
    helper(root);
    return res;
}
};