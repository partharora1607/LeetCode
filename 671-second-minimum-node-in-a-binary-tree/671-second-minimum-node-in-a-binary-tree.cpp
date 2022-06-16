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
int min_value;
int sec_min_value ;
bool flag = false;

void helper(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    } 
    if(root->val == INT_MAX){
        flag = true;
    }
    if (root->val < min_value)
    {
        sec_min_value = min_value;
        min_value = root->val;
    }
    if (root->val > min_value && root->val < sec_min_value)
    {
        sec_min_value = root->val;
    }
    helper(root->left);
    helper(root->right);
}

int findSecondMinimumValue(TreeNode *root)
{
    min_value = INT_MAX;
    sec_min_value  = INT_MAX;
    helper(root);
    if(sec_min_value == INT_MAX && flag == false) {
        return -1;
    }
    if(sec_min_value == min_value){
        return -1;
    }
    return sec_min_value;
}
};