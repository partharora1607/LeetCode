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
    // Method - 1 (using a Queue + NULL for level)

vector<vector<int>> res;

void helper(TreeNode *root){
    if(!root) return;
    queue<TreeNode *> q1;
    q1.push(root);
    q1.push(NULL);
    vector<int> ar;
    while(!q1.empty()){
        TreeNode *front = q1.front();
        q1.pop();

        if(front!= NULL){
            ar.push_back(front->val);
            if(front->left){
                q1.push(front->left);
            }
            if(front->right) q1.push(front->right);
        } 
        else{
            res.push_back(ar);
            ar.clear();
            if(!q1.empty()){
                q1.push(NULL);
            }
        }
    }
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    helper(root);
    return res;
}
};