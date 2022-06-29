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
    
//     palindrome - > 1221 -> even-> freq of each element is even
//     12321 -> odd -> freq of each element is even except 1
//     Then it is a Palindrome :)
    
    
int ans = 0;

bool is_pseudo_palindromic(unordered_map<int, int> &mymap)
{
    if(mymap.size() <= 1){
        return true;
    }
    int odd = 0;
    unordered_map<int,int> ::iterator it = mymap.begin();
    while(it != mymap.end()){
        if(it->second % 2 == 1){
            odd++;
        }
        if(odd > 1){
            return false;
        }
        it++;
    }
    return true;
}

void helper(TreeNode *root, unordered_map<int, int> &mymap)
{
    if(root == NULL){
        return;
    }
    mymap[root->val]++;
    if(root->left == NULL && root->right == NULL){
        if(is_pseudo_palindromic(mymap)){
            ans++;
        }
    }
    helper(root->left , mymap);
    helper(root->right , mymap);
    mymap[root->val]--;
    if(mymap[root->val] == 0){
        mymap.erase(root->val);
    }

}

int pseudoPalindromicPaths(TreeNode *root)
{
    unordered_map<int, int> mymap;
    helper(root, mymap);
    return ans;
}
};