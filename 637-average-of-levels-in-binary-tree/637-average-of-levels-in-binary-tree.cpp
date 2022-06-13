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
    vector<double> averageOfLevels(TreeNode *root)
{
    vector<double> res;
    queue<TreeNode *> q1;
    q1.push(root);
    while(!q1.empty()){
        int n =q1.size();
        double sum = 0;
        for (int i = 0; i < n; i++)
        {   
           TreeNode *front = q1.front();
           q1.pop();
           sum += front->val;
           if(front->left) q1.push(front->left);
           if(front->right) q1.push(front->right);
        }
        sum /= n;
        res.push_back(sum);
    }
    return res;
}
};