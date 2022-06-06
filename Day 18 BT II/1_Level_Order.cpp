#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> ans;
        if(root==NULL)  return ans;
        vector<int> v;
        TreeNode* node;
        int level;
        map<int,vector<int>> m;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            node=it.first;
            level=it.second;
            if(m.find(level)==m.end())  m[level]=v;
            m[level].push_back(node->val);
            if(node->left)  q.push({node->left,level+1});
            if(node->right) q.push({node->right,level+1});
        }   
        for(auto it:m)    ans.push_back(it.second);
        return ans;
    }
};