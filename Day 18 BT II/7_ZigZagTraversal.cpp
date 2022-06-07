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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        bool l2r=true;
        vector<int> temp;
        TreeNode* node;
        int s,index;
        while(!q.empty()){
            s=q.size();
            temp.resize(s);
            for(int i=0;i<s;i++){    
                node=q.front();
                q.pop();
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
                index=l2r==true?i:s-1-i;
                temp[index]=node->val;
            }
            l2r=!l2r;
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};