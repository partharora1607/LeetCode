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
vector<int> v1;
vector<int> v2;
void inorder(TreeNode *root , vector<int>& v){
    if(root == NULL)
    {
        return;
    }
    v.push_back(-1);
    inorder(root->left , v);
    v.push_back(0);
    v.push_back(root->val);
    v.push_back(1);
    inorder(root->right , v);
}


bool isSameTree(TreeNode *p, TreeNode *q)
{
    inorder(p , v1);
    inorder(q , v2);
    return v1 == v2;
}
};