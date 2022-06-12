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
int max_freq = 0, currfreq = 0, precursor = INT_MIN;

void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);

    if (precursor == root->val)
    {
        currfreq++;
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
    else if (currfreq == max_freq)
    {
        res.push_back(root->val);
    }
    precursor = root->val;
    inorder(root->right);
}

vector<int> findMode(TreeNode *root)
{
    inorder(root);
    return res;
}

};