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
    // Method - 2 (Trying Iteratively)

bool check(TreeNode *root1 , TreeNode *root2){
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    if(root1->val != root2->val){
        return false;
    }
    return true;
}

bool helper(TreeNode *root1 , TreeNode *root2){

    if(!check(root1 , root2)) return false;
    queue<TreeNode *> q1;
    q1.push(root1);
    queue<TreeNode *> q2;
    q2.push(root2);
    while(!q1.empty() && !q2.empty()){
        TreeNode *front1 = q1.front();
        TreeNode *front2 = q2.front();
        q1.pop();
        q2.pop();

        if(!check(front1 , front2)) return false;
        if(front1)
        {
           q1.push(front1->left);
           q1.push(front1->right);
        }
        if(front2){
            q2.push(front2->right);
            q2.push(front2->left);
        }
    }
    return true;
}

bool isSymmetric(TreeNode *root)
{
    if(root == NULL){
        return true;
    }
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    return helper(root->left , root->right);
}
};