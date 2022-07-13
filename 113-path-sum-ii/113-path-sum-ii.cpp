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
vector<int> ar;
int sum = 0;

void helper(TreeNode *root , int targetsum){
    if(!root) return;
    sum += root->val;
    ar.push_back(root->val);
    if(root->left == NULL && root->right == NULL && sum == targetsum){
        res.push_back(ar);
        ar.pop_back();
        sum -= root->val;
        return;
    }
    helper(root->left , targetsum);
    helper(root->right , targetsum);
    ar.pop_back();
    sum -= root->val;
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    helper(root , targetSum);
    return res;
}
};