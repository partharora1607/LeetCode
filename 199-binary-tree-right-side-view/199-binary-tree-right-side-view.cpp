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
vector<vector<int>> v;

void helper(TreeNode *root)
{
    queue<TreeNode *> q1;
    q1.push(root);
    q1.push(NULL);
    while (!q1.empty())
    {
        TreeNode *front = q1.front();
        q1.pop();
        if (front)
        {
            res.push_back(front->val);
            if (front->left)
            {
                q1.push(front->left);
            }
            if (front->right)
            {
                q1.push(front->right);
            }
        }
        else
        {
            if (!q1.empty())
            {
                q1.push(NULL);
            }
            v.push_back(res);
            res.clear();
        }
    }
}

vector<int> rightSideView(TreeNode *root)
{
    if(root == NULL){
        return {};
    }
    vector<int> ans;
    helper(root);
    for (int i = 0; i < v.size(); i++)
    {
        int ei = v[i].size() - 1;
        ans.push_back(v[i][ei]);
    }
    return ans;
}
};