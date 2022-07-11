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

void helper(TreeNode *root){
    if(!root) return;
    queue<TreeNode *> q1;
    q1.push(root);
    vector<int> ar;
    while(!q1.empty()){
        int n = q1.size();
        for (int i = 0; i < n; i++)
        {   
           TreeNode *front = q1.front();
           q1.pop();
           ar.push_back(front->val);
            if(front->left) q1.push(front->left);
            if(front->right) q1.push(front->right);
        }
        res.push_back(ar);
        ar.clear();
    }
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    helper(root);
    return res;
}

};