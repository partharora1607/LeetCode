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
    bool isEvenOddTree(TreeNode *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        if(root->val % 2 != 0) return true;
        else return false;
    }
    int level = 0;
    int store = root->val;
    vector<int> ar;
    queue<TreeNode *> q1;
    q1.push(root);
    q1.push(NULL);
    while (!q1.empty())
    {
        TreeNode *front = q1.front();
        q1.pop();

        if (front != NULL)
        {
            ar.push_back(front->val);
            if (front->left)
                q1.push(front->left);
            if (front->right)
                q1.push(front->right);
        }
        if (front == NULL)
        {
            if (!q1.empty())
            {
                q1.push(NULL);
            }
            if (store % 2 != 0)
            {
                if (level >= 1 && level % 2 == 0)
                {
                    // even; -> odd and increasing
                    int prev = INT_MIN;
                    for (int i = 0; i < ar.size(); i++)
                    {
                        if (ar[i] % 2 != 0 && ar[i] > prev)
                        {
                            prev = ar[i];
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
                else if (level >= 1 && level % 2 != 0)
                {
                    // odd -> values even and decreasing
                    int prev = INT_MAX;
                    for (int i = 0; i < ar.size(); i++)
                    {
                        if (ar[i] % 2 == 0 && ar[i] < prev)
                        {
                            prev = ar[i];
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
            else
            {
                if (level >= 1 && level % 2 != 0)
                {
                    // even; -> odd and increasing
                    int prev = INT_MIN;
                    for (int i = 0; i < ar.size(); i++)
                    {
                        if (ar[i] % 2 != 0 && ar[i] > prev)
                        {
                            prev = ar[i];
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
                else if (level >= 1 && level % 2 == 0)
                {
                    // odd -> values even and decreasing
                    int prev = INT_MAX;
                    for (int i = 0; i < ar.size(); i++)
                    {
                        if (ar[i] % 2 == 0 && ar[i] < prev)
                        {
                            prev = ar[i];
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
            level++;
            ar.clear();
        }
    }
    return true;
}
};