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
    int maxLevelSum(TreeNode *root)
{
    int max_val = INT_MIN;
    int level_ans = 1;
    queue<TreeNode *> q1;
    q1.push(root);
    q1.push(NULL);
    int level = 1;
    int sum = 0;
    while (!q1.empty())
    {
        TreeNode *front = q1.front();
        q1.pop();

        if (front != NULL)
        {
            sum += front->val;
            if(front->left) q1.push(front->left);
            if(front->right) q1.push(front->right);
        }
        else{
            if(sum > max_val){
                max_val = sum;
                level_ans = level; 
            }
            if(!q1.empty()){
                q1.push(NULL);
            }
            level++;
            sum = 0;
        }
    }
    return level_ans;
}
};