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
    int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;
    queue<pair<TreeNode *, int>> q1;

    int max_width = 0;

    q1.push({root, 0});

    while (!q1.empty())
    {
        int n = q1.size();
        int first, second;
        for (int i = 0; i < n; i++)
        {
            TreeNode *front = q1.front().first;
            long int index = q1.front().second;

            q1.pop();

            long int lcI, rcI;
            lcI = 2 * index + 1;
            rcI = 2 * index + 2;

            if (i == 0)
            {
                first = index;
            }

            if (i == n - 1)
            {
                second = index;
            }

            if (front->left)
            {
                q1.push({front->left, lcI});
            }
            if (front->right)
            {
                q1.push({front->right, rcI});
            }
        }
        max_width = max(max_width, second - first + 1);
    }
    return max_width;
}
};