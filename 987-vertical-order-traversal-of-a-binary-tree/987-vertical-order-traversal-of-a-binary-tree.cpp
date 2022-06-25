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

vector<vector<int>> verticalTraversal(TreeNode* root) {
     vector<vector<int>> ans;
     if(root==NULL)
         return ans;
     //map with mapping horizonatl distance to mapp of level of nodes
     //we want in output sorted order of hd so take ordered map
     map<int, map<int,vector<int>>> m;
     //queue with node and hd,leve
     queue<pair<TreeNode*, pair<int,int>>> q;
     //root will hd as 0 and level also 0
     q.push({root,{0,0}});
     while(!q.empty())
     {
         pair<TreeNode*,pair<int,int>> temp=q.front();
         q.pop();
         //Node
         TreeNode* curr=temp.first;
         //hd
         int hd=temp.second.first;
         //level
         int level=temp.second.second;
         //push into map
         m[hd][level].push_back(curr->val);
         if(curr->left!=NULL)
         {
             q.push({curr->left,{hd-1,level+1}});
         }
         if(curr->right!=NULL)
         {
             q.push({curr->right,{hd+1,level+1}});
         }
     }
     for(auto it:m)
     {
         vector<int> v;
         for(auto j: it.second)
         {
             //if hd and level are same just sort them in increasing order
             sort(j.second.begin(),j.second.end());    
             for(auto k: j.second)
                 {
                     v.push_back(k);        
                 }
         }
         ans.push_back(v);
     }
     return ans;  
 }
};