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
class Pair
{
public:
    int maxvalue;
    int minvalue;
    bool isbst;
    int sum_of_nodes;
};   
    
int sum = INT_MIN;

Pair *helper(TreeNode *root)
{
    if (root == NULL)
    {
        Pair *p1 = new Pair();
        p1->isbst = true;
        p1->maxvalue = INT_MIN;
        p1->minvalue = INT_MAX;
        p1->sum_of_nodes = 0;
        return p1;
    }

    Pair *leftans = helper(root->left);
    Pair *rightans = helper(root->right);

    Pair *ans = new Pair();

    ans->maxvalue = max(root->val, max(leftans->maxvalue, rightans->maxvalue));
    ans->minvalue = min(root->val, min(leftans->minvalue, rightans->minvalue));
    ans->sum_of_nodes = leftans->sum_of_nodes + rightans->sum_of_nodes + root->val;
    ans->isbst = (leftans->isbst && rightans->isbst) && (root->val > leftans->maxvalue && root->val < rightans->minvalue);
    if (ans->isbst)
    {
        sum = max(sum, ans->sum_of_nodes);
    }
    return ans;
}

int maxSumBST(TreeNode *root)
{
    helper(root);
    if(sum < 0){
        return 0;
    }
    return sum;
}
};