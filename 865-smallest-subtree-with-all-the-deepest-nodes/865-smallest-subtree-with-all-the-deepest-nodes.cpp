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
    // root , depth     
    pair<TreeNode *, int> *helper(TreeNode *root)
{
    if (root == NULL)
    {
        return new pair<TreeNode *, int>(NULL, 0);
    }

    pair<TreeNode *, int> *leftans = helper(root->left);
    pair<TreeNode *, int> *rightans = helper(root->right);

    pair<TreeNode *, int> *ans = new pair<TreeNode *, int>();
    ans->second = max(leftans->second , rightans->second) + 1;

    if(leftans->second == rightans->second){
        ans->first = root;
    }
    else if(leftans->second > rightans->second){
        ans->first = leftans->first;
    }
    else{
        ans->first = rightans->first;
    }      
    return ans;
}

TreeNode *subtreeWithAllDeepest(TreeNode *root)
{
    return helper(root)->first;
}
};