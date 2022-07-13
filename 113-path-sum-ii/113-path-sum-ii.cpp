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

void helper(TreeNode *root , int targetsum , int sum , vector<int> &ar){
    if(!root) return;
    sum += root->val;
    ar.push_back(root->val);
    if(root->left == NULL && root->right == NULL && targetsum == sum){
        res.push_back(ar);
        ar.pop_back();
        return;
    }   
    helper(root->left , targetsum, sum , ar);
    helper(root->right , targetsum , sum , ar);
    ar.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<int> ar;
    helper(root , targetSum , 0 , ar);
    return res;
}
};