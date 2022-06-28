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
    int res = 0;  

// min , max
pair<int,int> *helper(TreeNode *root){
    if(root == NULL){
        return new pair<int,int>(INT_MAX, INT_MIN);
    }
    pair<int,int> *leftans = helper(root->left);
    pair<int,int> *rightans = helper(root->right);

    int tmin = min(leftans->first , rightans->first);
    int tmax = max(leftans->second , rightans->second);

    if(tmin != INT_MAX){
        res = max(res , abs(root->val - tmin));
    }
    if(tmax != INT_MIN){
        res = max(res,abs(root->val - tmax));
    }

    pair<int,int> *ans = new pair<int,int>();
    ans->first = min(root->val , tmin);
    ans->second = max(root->val , tmax);

    return ans;
}

int maxAncestorDiff(TreeNode *root)
{
    helper(root);
    return res;
}
};