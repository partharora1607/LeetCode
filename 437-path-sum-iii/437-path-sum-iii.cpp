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
    int find_paths(TreeNode *root, int target , long long int sum = 0)
{
    if (root == NULL)
        return 0;
    sum += root->val;
    int ans = 0;
    if(sum == target){
        ans += 1;
    }
    int leftans = find_paths(root->left , target , sum);
    int rightans = find_paths(root->right , target , sum); 
    return leftans + rightans + ans;
}

int pathSum(TreeNode *root, int targetSum)
{
    if (root == NULL)
        return 0;
    int ans1 = find_paths(root, targetSum);
    int leftans = pathSum(root->left, targetSum);
    int rightans = pathSum(root->right, targetSum);
    return ans1 + leftans + rightans;
}
};