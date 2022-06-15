/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
vector<int> ans;
void print_node_at_distance_k(TreeNode *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        ans.push_back(root->val);
        return;
    }
    print_node_at_distance_k(root->left, k - 1);
    print_node_at_distance_k(root->right, k - 1);
}

vector<TreeNode *> res;
vector<char> v;
    
bool findNode(TreeNode *root, TreeNode *target)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->val == target->val)
    {
        res.push_back(root);
        return true;
    }
    bool leftans = findNode(root->left, target);
    if (leftans == true)
    {
        res.push_back(root);
        v.push_back('L');
        return true;
    }
    bool rightans = findNode(root->right, target);
    if (rightans == true)
    {
        res.push_back(root);
        v.push_back('R');
        return true;
    }
    return false;
}


vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    findNode(root, target);
    print_node_at_distance_k(res[0], k);
    // k--;
    for (int i = 1; i < res.size(); i++)
    {
        k--;
        if(k == 0){
            ans.push_back(res[i]->val);
        }
        else if(k > 0)
        {
            if (v[i - 1] == 'L')
            {
                print_node_at_distance_k(res[i]->right, k - 1);
            }
            else if (v[i - 1] == 'R')
            {
                print_node_at_distance_k(res[i]->left , k - 1);
            }    
        }
        else
        {
            break;
        }
    }
    return ans;
}
};