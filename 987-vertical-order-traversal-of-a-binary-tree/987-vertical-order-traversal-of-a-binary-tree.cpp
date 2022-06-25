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
    map<int, vector<int>> mymap;

void helper(TreeNode *root)
{
    if (!root)
        return;
    // node , col
    queue<pair<TreeNode *, int>> q1;

    q1.push({root, 0});
    vector<pair<int, int>> v;
    while (!q1.empty())
    {
        int n = q1.size();
        for (int i = 0; i < n; i++)
        {
            pair<TreeNode *, int> p1 = q1.front();
            q1.pop();

            TreeNode *front = p1.first;
            int col = p1.second;

            v.push_back({front->val, col});

            if (front->left)
            {
                q1.push({front->left, col - 1});
            }

            if (front->right)
            {
                q1.push({front->right, col + 1});
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            int f = v[i].second; // col
            int s = v[i].first;  // val
            mymap[f].push_back(s);
        }
        v.clear();
    }
}
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    helper(root);
    vector<vector<int>> v;
    map<int, vector<int>>::iterator it = mymap.begin();
    while (it != mymap.end())
    {
        v.push_back(it->second);
        it++;
    }
    return v;
}
};