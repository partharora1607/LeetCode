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
    
 
int count = 0;
// depth , freq
unordered_map<int, int> helper(TreeNode *root, int d, int depth)
{
    if (root == NULL)
    {
        unordered_map<int, int> mymap;
        return mymap;
    }

    if (root->left == NULL && root->right == NULL)
    {
        unordered_map<int, int> mymap;
        mymap[depth]++;
        return mymap;
    }

    unordered_map<int, int> leftans = helper(root->left, d, depth + 1);
    unordered_map<int, int> rightans = helper(root->right, d, depth + 1);

    unordered_map<int, int>::iterator leftit = leftans.begin();
    unordered_map<int, int>::iterator rightit = rightans.begin();

    unordered_map<int, int> fans;

    while (leftit != leftans.end())
    {
        rightit = rightans.begin();
        while (rightit != rightans.end())
        {
            if (abs(leftit->first - depth) + abs(rightit->first - depth) <= d)
            {
                count += leftit->second * rightit->second;
            }
            rightit++;
        }
        leftit++;
    }

    leftit = leftans.begin();
    rightit = rightans.begin();

    while (leftit != leftans.end())
    {
        int f, s;
        f = leftit->first;
        s = leftit->second;
        fans[f] += s;
        leftit++;
    }

    while (rightit != rightans.end())
    {
        int f, s;
        f = rightit->first;
        s = rightit->second;
        fans[f] += s;
        rightit++;
    }
    return fans;
}

int countPairs(TreeNode *root, int distance)
{
    helper(root , distance , 0);
    return count;
}  
};