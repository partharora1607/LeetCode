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

vector<int> largestValues(TreeNode *root)
{
    if (!root)
        return {};
    queue<TreeNode *> q1;
    q1.push(root);
    q1.push(NULL);
    int maxdata = INT_MIN;
    while (!q1.empty())
    {
        TreeNode *front = q1.front();
        q1.pop();

        if (front == NULL)
        {
            res.push_back(maxdata);
            maxdata = INT_MIN;
            if (!q1.empty())
            {
                q1.push(NULL);
            }
        }
        else
        {
            maxdata = max(maxdata, front->val);
            if (front->left)
                q1.push(front->left);
            if (front->right)
                q1.push(front->right);
        }
    }
    return res;
}
};