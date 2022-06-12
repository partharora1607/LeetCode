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
    unordered_map<int,int> mymap;
int maxcount;// take care of that perticular max value

// return sum of subtrees
int helper(TreeNode *root){
    if(!root) return 0;
    int sum = root->val + helper(root->left) + helper(root->right);
    maxcount = max(maxcount , ++mymap[sum]);
    return sum;
}

vector<int> findFrequentTreeSum(TreeNode *root)
{
    vector<int> res;
    helper(root);
    auto it = mymap.begin();
    for (; it != mymap.end(); it++)
    {   
       if(it->second == maxcount){
        res.push_back(it->first);
       }
    }
    return res; 
}

};