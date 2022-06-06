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

int getMaxWidth(TreeNode *root)
{
    queue<pair<TreeNode*, int>> q;
    TreeNode* node;
    long long first, last, s, curr, mini,ans=0;
    q.push({root,0});
    while(!q.empty()){
        s=q.size();
        mini=q.front().second;
        for(int i=0;i<s;i++){
            auto element=q.front();
            q.pop();
            curr=element.second-mini;
            node=element.first;
            if(i==0)    first=curr;
            else if(i==s-1) last=curr;
            if(node->left)  q.push({node->left, curr*2+1});
            if(node->right)  q.push({node->right, curr*2+2});
        }
        ans=max(ans, last-first+1);
    }   
    return ans;
}