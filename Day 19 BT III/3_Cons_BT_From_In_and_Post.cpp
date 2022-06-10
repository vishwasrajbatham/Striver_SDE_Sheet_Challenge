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
    TreeNode* buildTreePostIn(vector<int> &inorder, int in_start, int in_end, vector<int> &postorder, int post_start, int post_end,  map<int,int> &mp){
        if (post_start>post_end || in_start>in_end) return NULL;
        TreeNode* root = new TreeNode(postorder[post_end]);
        int ri = mp[postorder[post_end]];
        TreeNode* leftchild = buildTreePostIn(inorder, in_start, ri-1, postorder, post_start, post_start+ri-in_start-1, mp);
        TreeNode* rightchild = buildTreePostIn(inorder,ri+1, in_end, postorder, post_start+ri-in_start, post_end-1, mp);
        root->left = leftchild;
        root->right = rightchild;
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size())    return NULL;
        map<int,int> mp;
        for (int i=0;i<inorder.size();++i)    mp[inorder[i]] = i;
        return buildTreePostIn(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1,mp);
    }
    
};