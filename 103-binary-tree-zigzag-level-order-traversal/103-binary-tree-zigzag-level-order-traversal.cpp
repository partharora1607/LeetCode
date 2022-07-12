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
        vector<vector<int>> res;

void helper(TreeNode *root)
{
    // edge case
    if (!root)
        return;

    stack<TreeNode *> s1;
    stack<TreeNode *> s2;

    vector<int> ar;

    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            TreeNode *top = s1.top();
            s1.pop();

                ar.push_back(top->val);
                if (top->left)
                    s2.push(top->left);
                if (top->right)
                    s2.push(top->right);
            
        }
        if(ar.size() > 0){
            res.push_back(ar);
        }
        ar.clear();
        while (!s2.empty())
        {
            TreeNode *top = s2.top();
            s2.pop();

                ar.push_back(top->val);
                if (top->right)
                    s1.push(top->right);
                if (top->left)
                    s1.push(top->left);
            
        }
        if(ar.size() > 0){
            res.push_back(ar);
        }
        ar.clear();
    }
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    helper(root);
    return res;
}
};