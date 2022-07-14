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
    unordered_map<int, int> mymap;
int max_freq = 0;

vector<int> res;

int helper(TreeNode *root){
    if(root == NULL) return 0;
    int sum = root->val + helper(root->left) + helper(root->right);
    mymap[sum]++;
    if(mymap[sum] > max_freq){
        max_freq = mymap[sum];
        res.clear();
        res.push_back(sum);
    }
    else if(mymap[sum] == max_freq){
        res.push_back(sum);
    }
    return sum;
}

vector<int> findFrequentTreeSum(TreeNode *root)
{
    helper(root);
    return res;
}
};